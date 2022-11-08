/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processing.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:06 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 16:36:31 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PROCESSING_H
# define ARGS_PROCESSING_H
/*
 * @return 1 if is num and 0 if not
 */
int	ft_is_num(char chr);

/*
 * @return the number in int if usable,-1 if no usable(letter or neggative)
 */
int	ft_atoi(char *str);

/*
 * @return the number of digits n has (ex: 142 is 3)
 */
int	get_base(int n);
#endif
