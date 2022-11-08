/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 21:19:12 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"
#include <stdlib.h>

t_square	*init_square(int x, int y)
{
	t_square	*sqr;

	sqr = (t_square *) malloc(sizeof(t_square));
	sqr->x = x;
	sqr->y = y;
	sqr->d = 1;
	return (sqr);
}

int	can_grow(int **map, t_square sqr, t_caption cap)
{
	int	i;
	int	j;

	i = sqr.x + sqr.d;
	j = sqr.y + sqr.d;
	if (cap.num_rows < i || cap.num_columns < j)
		return (0);
	while (sqr.x <= i)
	{
		if (map[i][j] == 1)
			return (0);
		i--;
	}
	i = sqr.x + sqr.d;
	while (sqr.y <= j)
	{
		if (map[i][j] == 1)
			return (0);
		j--;
	}
	return (1);
}
