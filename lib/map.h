/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:35 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/08 02:16:25 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "square.h"
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief	Prints a map pre-formated without the caption characters.
 * 
 * @param map   Map state to print.
 * @param dim   Map's dimension.
 */
void		print_map_cheat(int **map, int dim);

/**
 * @brief   Prints the map with the solution square,
 *      	using the caption characters.
 * 
 * @param map   Map instance for the problem.
 * @param sol	Solution square.
 * @param cap   Caption characters.
 * @param dim	Map dimension.
 */
void		print_solution(int **map, t_square sol, char cap[3], int dim);

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
 * 
 * @return  Biggest square on the map.
 */
t_square	*find_max_square(int **map, int dim);

#endif
