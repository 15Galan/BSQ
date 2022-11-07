/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 00:36:43 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/search_square.h"

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

t_square	*initialize_square(int x, int y)
{
	t_square	*sqr;

	sqr = (t_square *) malloc(sizeof(t_square));
	sqr->x = x;
	sqr->y = y;
	sqr->d = 1;
	return (sqr);
}

int	can_grow(int **map, const t_square a, const t_square b)
{
	int	i;
	int	j;

	i = a.x;
	j = a.y;
	if (map[i + 1][j] != 1 && map[i][j + 1] != 1 && i < b.x && j < b.y)
		return (1);
	return (0);
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
			calculate_square(map, sol, *end);
			j++;
		}
		i++;
	}
	free(end);
	return (sol);
}
