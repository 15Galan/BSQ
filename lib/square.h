/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:42:30 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 00:58:17 by antgalan         ###   ########.fr       */
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
 * @brief  	Checks if a solution square can
 * 			grow, being a better solution.
 * 
 * @param map	Map instance to check.
 * @param a 	Current solution square.
 * @param b 	New solution square.
 * 
 * @return int 	'1' if it can grow; '0' otherwise.
 */
int			can_grow(int **map, const t_square a, const t_square b);

#endif
