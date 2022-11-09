/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 08:51:48 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 14:37:02 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caption.h"
#include "ft_str.h"
#include "square.h"
#include "map.h"
#include <stdlib.h>

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
	t_caption	caption;
	t_square	*bsq;
	int			**map;
	int			flag_error;
	int			i;

	i = 0;
	while (++i < argc)
	{
		flag_error = 0;
		map = create_map_from_file(*(argv + i), &caption, &flag_error);
		if (flag_error == 0)
		{
			bsq = find_max_square(map, caption);
			print_solution(map, *bsq, caption, ' ');
			free(bsq);
		}
		else
			ft_putstr("map error");
		free_map(map, caption.rows);
	}
	exit(0);
}
