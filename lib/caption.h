/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caption.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:27:49 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 09:33:26 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTION_H
# define CAPTION_H

/**
 * @brief	Contains information about a map.
 * @cite	It's found in the first line of the map file.
 * 
 * @param rows      Number of rows in the map.
 * @param cols      Number of columns in the map.
 * @param empty     Character used to represent empty spaces.
 * @param obstacle  Character used to represent obstacles.
 * @param full      Character used to represent solution spaces.
 */
typedef struct s_caption
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}	t_caption;

/*
 * @brief initializes the structure t_caption
 */
t_caption	fill_caption(char *raw, int *flag_error);

#endif
