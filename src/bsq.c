/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:51:48 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 02:08:20 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caption.h"
#include "ft_str.h"
#include "square.h"
#include "map.h"
#include <stdio.h>

int	**create_map_from_file(char *path, t_caption *caption, int *flag_error);

// t_square not declared until merge:
// t_square max_square;
// flag_error = 0 not necesary. Just for security but redundat
// 
// print info about map
// printf("%c %c %c col: %d rows: %d\n", caption.empty, 
// caption.obstacle, caption.full, caption.num_columns, caption.num_rows);
// printf("status error: %d\n", flag_error);
int	main(int argc, char **argv)
{
	int			**map;
	t_caption	caption;
	int			flag_error;
	t_square	*bsq;

	flag_error = 0;
	if (argc == 2)
	{
		map = create_map_from_file(*(argv + 1), &caption, &flag_error);
		if (map != NULL)
		{
			bsq = find_max_square(map, caption);
			print_solution(map, *bsq, caption);
		}
	}
}
