/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:44:51 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 20:34:12 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/square.h"
#include "../lib/map.h"

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

void	print_solution(int **map, t_square sol, char cap[3], int dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (sol.x <= i && i < sol.x + sol.d
				&& sol.y <= j && j < sol.y + sol.d)
				write(1, &cap[2], 1);
			else if (map[i][j] == 1)
				write(1, &cap[1], 1);
			else
				write(1, &cap[0], 1);
			j++;
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

t_square	*calculate_square(int **map, t_square *sqr, int max)
{
	int	i;
	int	j;

	i = sqr->x;
	j = sqr->y;
	while (can_grow(map, *sqr, max))
	{
		i++;
		j++;
		sqr->d++;
	}
	return (sqr);
}

t_square	*find_max_square(int **map, int dim)
{
	t_square	*sol;
	t_square	*new;
	t_square	*end;
	int			i;
	int			j;

	sol = init_square(0, 0);
	end = init_square(dim - 1, dim - 1);
	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if (map[i][j] != 1)
			{
				new = calculate_square(map, init_square(i, j), dim - sol->d + 1);
				if (sol->d < new->d)
					*sol = *new;
				free(new);
			}
		}
	}
	free(end);
	return (sol);
}
