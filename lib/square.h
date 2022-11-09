/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:42:30 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/09 02:31:38 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "caption.h"

/**
 * @brief	Represents a square.
 * 
 * @param x		Square's top-left horizontal coordinate.
 * @param y		Square's top-left vertical coordinate.
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
 * @param y 	Square's top-left vertical coordinate.
 * 
 * @return	Initilized square.
 */
t_square	*init_square(int x, int y);

/**
 * @brief	Increments the square's dimensions while
 * 			it has a valid size and is still a square.
 * @cite	A square is valid if it doesn't overlap with an
 * 			obstacle and if it doesn't exceed the map's limits.
 * 			
 * @param map	The map to check.
 * @param sqr 	The square to increment.
 * @param cap 	The map's caption.
 */
t_square	*grow_square(int **map, t_square *sqr, t_caption max);

#endif
