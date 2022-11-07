/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:32:35 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/07 23:42:35 by antgalan         ###   ########.fr       */
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
 * @brief   Place an '8' on the board for each position
 *          that connects orthogonally to an obstacle.
 * 
 * @param brd   Board status.
 * @param x     Obstacle horizontal coordinate.
 * @param y     Obstacle vertical coordinate.
 * @param max   Board dimension.
 */
void	put_orthogonal_limits(int **brd, int x, int y, int max);

#endif
