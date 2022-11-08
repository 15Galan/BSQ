/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:08:25 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 15:08:50 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	p;

	p = 0;
	while (str [p] != 0)
	{
		write(1, str + p, 1);
		p++;
	}
}

int	ft_is_printable(char str)
{
	if (!(str < ' ' || str > '~'))
		return (1);
	return (0);
}
