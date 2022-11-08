/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/09 00:47:29 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "map.h"
#include <stdlib.h>

t_square	*init_square(int x, int y)
{
	t_square	*sqr;

	sqr = malloc(sizeof(t_square));
	if (sqr == NULL)
		return (NULL);
	sqr->x = x;
	sqr->y = y;
	sqr->d = 1;
	return (sqr);
}

int	can_grow(int **map, t_square sqr, t_caption cap)
{
	int	i;
	int	j;

	i = sqr.x;
	while (i < sqr.x + sqr.d)
	{
		j = sqr.y;
		while (j < sqr.y + sqr.d)
		{
			if (map[i][j] == 1)
				return (0);
			j++;
		}
		i++;
	}
	if (cap.num_rows <= sqr.x + sqr.d || cap.num_columns <= sqr.y + sqr.d)
		return (0);
	return (1);
}
