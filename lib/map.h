/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:35 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/09 02:43:10 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "caption.h"

/**
 * @brief	Prints a map pre-formated without the caption characters.
 * 
 * @param map   Map state to print.
 * @param cap   Map's caption.
 * @param del   Delimiter character ('\0' for no delimiter).
 */
void		print_map(int **map, t_caption cap, char del);

/**
 * @brief   Prints the map with the solution square,
 *      	using the caption characters.
 * 
 * @param map   Map state to print.
 * @param cap   Map's caption.
 * @param del   Delimiter character ('\0' for no delimiter).
 */
void		print_solution(int **map, t_square sol, t_caption cap, char del);

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
 * @brief   Increases the dimensions of a square..
 * 
 * @param map   Map instance for the problem.
 * @param sqr   Square to calculate.
 * @param max   Maximum limit to reach.
 */
t_square	*update_square(int **map, t_square *sqr, t_caption cap);

/**
 * @brief	Finds the biggest square on the map.
 * 
 * @param map	Map instance for the problem.
 * @param dim	Map dimension.
 * 
 * @return  Biggest square on the map.
 */
t_square	*find_max_square(int **map, t_caption cap);

#endif
