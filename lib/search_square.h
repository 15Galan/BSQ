/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:35 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 00:36:36 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_SQUARE_H
# define SEARCH_SQUARE_H

# include <unistd.h>
# include <stdlib.h>

/**
 * @brief	Represents a square.
 * 
 * @param x		Origin's horizontal coordinate.
 * @param y		Origin's vertical coordinate.
 * @param d		Length of the square's diagonal.
 */
typedef struct s_square
{
	int	x;
	int	y;
	int	d;
}	t_square;

/**
 * @brief   Places an '8' on the board for each position
 *          that connects orthogonally to an obstacle.
 * 
 * @param map   Map state to modify.
 * @param x     Obstacle horizontal coordinate.
 * @param y     Obstacle vertical coordinate.
 * @param dim   Map dimension.
 */
void		put_orthogonal_limits(int **map, int x, int y, int dim);

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

/**
 * @brief   Calculates the best solution square.
 * 
 * @param map   Map instance for the problem.
 * @param sqr   Current solution square.
 * @param new   New solution square to compare.
 */
void		calculate_square(int **map, t_square *sqr, t_square new);

/**
 * @brief	Finds the biggest square on the map.
 * 
 * @param map	Map instance for the problem.
 * @param dim	Map dimension.
 */
t_square	*find_max_square(int **map, int dim);

#endif
