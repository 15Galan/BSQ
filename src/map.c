/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:44:51 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 01:08:19 by antgalan         ###   ########.fr       */
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

void	calculate_square(int **map, t_square *sqr, t_square new)
{
	t_square	*aux;

	aux = initialize_square(new.x, new.y);
	while (can_grow(map, *aux, new))
	{
		aux->x++;
		aux->y++;
		aux->d++;
	}
	if (sqr->d < aux->d)
		sqr = aux;
	free(aux);
}

t_square	*find_max_square(int **map, int dim)
{
	t_square	*sol;
	t_square	*new;
	t_square	*end;
	int			i;
	int			j;

	sol = initialize_square(0, 0);
	end = initialize_square(dim, dim);
	i = 0;
	while (i < end->x && i < dim - sol->d)
	{
		j = 0;
		while (j < end->y && j < dim - sol->d)
		{
			new = initialize_square(i, j);
			if (map[i][j] == 0)
				calculate_square(map, sol, *new);
			free(new);
			j++;
		}
		i++;
	}
	free(end);
	return (sol);
}
