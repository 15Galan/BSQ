/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 00:58:37 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/square.h"
#include "../lib/map.h"

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
	return (map[a.x + 1][a.y] != 1
		&& map[a.x][a.y + 1] != 1
		&& a.x < b.x
		&& a.y < b.y);
}
