/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:19 by antgalan          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:18 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_square
{
	int	org_x;
	int	org_y;

	int	dst_x;
	int	dst_y;

	int	side;
}	t_square;

void	put_orthogonal_limits(int **brd, int x, int y, int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (i == x || j == y)
				brd[i][j] = 8;
			j++;
		}
		i++;
	}
}
