/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:42:30 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 16:29:12 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include <stdlib.h>

/**
 * @brief	Represents a square.
 * 
 * @param x		Square's top-left horizontal coordinate.
 * @param y		Square's top-left horizontal coordinate.
 * @param d		Length of the square's diagonal.
 */
typedef struct s_square
{
	int	x;
	int	y;
	int	d;
}	t_square;

/**
 * @brief	Initializes a square with the minimum diagonal
 * 			value on the (x, y) coordinate of the map.	
 * 
 * @param x 	Square's top-left horizontal coordinate.
 * @param y 	Square's top-left horizontal coordinate.
 * 
 * @return	Initilized square.
 */
t_square	*initialize_square(int x, int y);

/**
 * @brief  	Checks if a square can grow
 * 
 * @param map	Map instance to check.
 * @param sqr 	Square to change size.
 * @param max   Maximum limit to reach.
 * 
 * @return int 	'1' if it can grow; '0' otherwise.
 */
int			can_grow(int **map, const t_square sqr, int max);

#endif
