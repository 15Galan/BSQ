/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:44:51 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 21:21:33 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"
#include <unistd.h>
#include <stdlib.h>

void	print_map_cheat(int **map, int dim)
{
	char	n;
	int		i;
	int		j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			n = '0' + map[i][j];
			write(1, &n, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_solution(int **map, t_square sol, t_caption cap)
{
	char	n;
	int		i;
	int		j;

	i = 0;
	while (i < cap.num_rows)
	{
		j = 0;
		while (j < cap.num_columns)
		{
			if (sol.x <= i && i < sol.x + sol.d
				&& sol.y <= j && j < sol.y + sol.d)
				n = '0' + cap.full;
			else if (map[i][j] == 1)
				n = '0' + cap.obstacle;
			else
				n = '0' + cap.empty;
			j++;
			write(1, &n, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	put_orthogonal_limits(int **map, int x, int y, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if ((i == x || j == y) && !(i == x && j == y) && map[i][j] != 1)
				map[i][j] = 8;
			j++;
		}
		i++;
	}
}

t_square	*update_square(int **map, t_square *sqr, t_caption cap)
{
	int	i;
	int	j;

	i = sqr->x;
	j = sqr->y;
	while (can_grow(map, *sqr, cap))
	{
		i++;
		j++;
		sqr->d++;
	}
	return (sqr);
}

t_square	*find_max_square(int **map, t_caption cap)
{
	t_square	*sol;
	t_square	*new;
	t_square	*end;
	int			i;
	int			j;

	sol = init_square(0, 0);
	end = init_square(cap.num_rows - 1, cap.num_columns - 1);
	i = -1;
	while (++i < cap.num_rows)
	{
		j = -1;
		while (++j < cap.num_columns)
		{
			if (map[i][j] != 1)
			{
				new = update_square(map, init_square(i, j), cap);
				if (sol->d < new->d)
					*sol = *new;
				free(new);
			}
		}
	}
	free(end);
	return (sol);
}
