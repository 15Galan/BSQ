/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:51:48 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 15:05:16 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "caption.h"
#include "ft_str.h"

#include <stdio.h>

int **create_map_from_file(char *path, t_caption *caption, int *flag_error);

//t_square not declared until merge:
	//t_square max_square;
//flag_error = 0 not necesary. Just for security but redundat
int main(int argc, char **argv)
{
	int	**map;
	t_caption caption;
	int flag_error;

	flag_error = 0;
	if(argc == 2)
	{
		map = create_map_from_file(*(argv+1), &caption, &flag_error);


		printf("%c %c %c col: %d rows: %d\n",caption.empty,caption.obstacle, caption.full, caption.num_columns, caption.num_rows); 
		printf("status error: %d\n", flag_error);

		int i2 = 0;
		int j2 = 0;
		while(i2 < caption.num_columns)
		{
			while(j2 < caption.num_rows)
			{
				printf("%d ",map[i2][j2]);
				j2++;
			}
			i2++;
			j2 = 0;
			printf("\n");
		}
	}
}
