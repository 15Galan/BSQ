/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:06 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 09:39:39 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PROCESSING_H
# define ARGS_PROCESSING_H

/**
 * @brief   Get the base number of a power.
 * 
 * @param n     Number to get the base.
 *
 * @return  The base number.
 */
int	get_base(int n);

/*
 * @param Positive number in string whitout spaces and simbol
 *
 * @return Value in Integer
 */
int ft_atoi(char *num);

#endif
