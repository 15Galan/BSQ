/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:01:54 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 02:04:50 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

/**
 * @brief   Prints a character.
 * 
 * @param c     Character to print. 
 */
void	ft_putchar(char c);

/**
 * @brief   Prints a string.
 * 
 * @param str   String to print.
 */
void	ft_putstr(char *str);

/**
 * @brief   Checks if a character is a number.
 * 
 * @param chr   Character to check.
 */
int		ft_is_num(char c);

/**
 * @brief   Checks if a character is printable.
 * @cite    It's between 32 (' ') and 126 ('~').
 * 
 * @param c   Character to check.
 * 
 * @return  1 if it's printable; 0 otherwise.
 */
int		ft_is_printable(char c);

/**
 * @brief   Transform a number in string format to an integer.
 * @cite    "Array TO Integer".
 * @cite    It's either a space (' '), a tab ('\t'), a newline ('\n'), a
 *          vertical tab ('\v'), a carriage return ('\r'), or a form feed ('\f').
 * 
 * @param str   String to transform.
 * 
 * @return  The integer value of the string.
 */
int		ft_atoi(char *str);

#endif
