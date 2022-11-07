/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/07 23:51:34 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/search_square.h"

void	put_orthogonal_limits(int **brd, int x, int y, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if ((i == x || j == y) && !(i == x && j == y) && brd[i][j] != 1)
				brd[i][j] = 8;
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

int	can_grow(int **brd, const t_square a, const t_square b)
{
	int	i;
	int	j;

	i = a.x;
	j = a.y;
	if (brd[i + 1][j] != 1 && brd[i][j + 1] != 1 && i < b.x && j < b.y)
		return (1);
	return (0);
}

void	calculate_square(int **brd, t_square *sqr, t_square now)
{
	t_square	*aux;
	int			i;
	int			j;

	aux = initialize_square(now.x, now.y);
	i = aux->x;
	j = aux->y;
	while (can_grow(brd, *aux, now))
	{
		aux->x++;
		aux->y++;
		aux->d++;
	}
	if (sqr->d < aux->d)
		sqr = aux;
	free(aux);
}

t_square	*find_max_square(int **brd, int dim)
{
	t_square	*bst;
	t_square	*end;
	int			i;
	int			j;

	bst = initialize_square(0, 0);
	end = initialize_square(dim, dim);
	i = 0;
	while (i < end->x && i < dim - bst->d)
	{
		j = 0;
		while (j < end->y && j < dim - bst->d)
		{
			calculate_square(brd, bst, *end);
			j++;
		}
		i++;
	}
	free(end);
	return (bst);
}
