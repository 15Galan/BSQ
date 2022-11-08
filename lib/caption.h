/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caption.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:27:49 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 16:37:23 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTION_H
# define CAPTION_H

/*
 * @brew to save parameters of the origin file
 */
typedef struct t_caption
{
	int		num_rows;
	int		num_columns;
	char	empty;
	char	obstacle;
	char	full;
}t_caption;

#endif
