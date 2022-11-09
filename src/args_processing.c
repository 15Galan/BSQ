/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:20:09 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 02:07:53 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_num(char chr)
{
	int	flag;

	flag = 1;
	if (chr < 48 || chr > 57)
		flag = 0;
	return (flag);
}

// No spaces before and after
int	ft_atoi(char *str)
{
	int	digit;
	int	i;
	int	number;

	if (str == NULL)
		return (-1);
	i = 0;
	number = 0;
	if (ft_is_num(str[i]) == 0 || str[i] == '0')
	{
		return (-1);
	}
	while (ft_is_num(str[i]) == 1)
	{
		digit = str[i] - '0';
		number = (number * 10) + digit;
		i++;
	}
	return (number);
}

int	get_base(int n)
{
	int	total;
	int	exponent;

	exponent = 0;
	total = 1;
	if (n < 10)
		return (1);
	while (n > total)
	{
		total *= 10;
		exponent++;
	}
	return (exponent + 1);
}
