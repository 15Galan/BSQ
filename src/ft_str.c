/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:08:25 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 01:58:01 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	ft_is_printable(char c)
{
	if (!(c < ' ' || c > '~'))
		return (1);
	return (0);
}
