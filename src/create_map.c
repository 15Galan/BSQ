/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:03:11 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 09:36:13 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_processing.h"
#include "caption.h"
#include "ft_str.h"
#include "file_manage.h"

#include <stdlib.h>

int	elem_from_caption(char element, t_caption caption)
{
	if (element == caption.empty)
		return (0);
	else if (element == caption.obst)
		return (1);
	else
		return (-1);
}

// fill the maps and check if is correct.
// if is not correct, error = -1
// 
// *
// if(raw[displacement + 4] != '\n')
//        *flag_error = 1
void	fill_map(int **map, t_caption *caption, char *raw, int *flag_error)
{
	int	raw_pos;
	int	i;
	int	j;

	raw_pos = 0;
	i = 0;
	j = -1;
	while (raw[raw_pos + 1] != '\n')
		raw_pos++;
	while (raw[(++raw_pos) + 1] != '\0' && j < caption->rows)
	{
		if (raw[raw_pos] == '\n')
		{
			map[++j] = (int *)malloc(sizeof(int) * caption->cols);
			*flag_error = (i != caption->cols && j - 1 != 0);
			i = 0;
		}
		else
		{
			map[j][i++] = elem_from_caption(raw[raw_pos], *caption);
			*flag_error += (elem_from_caption(raw[raw_pos], *caption) == 2);
		}
	}
	*flag_error += (raw[(++raw_pos) + 1] != '\0');
}

// if we cannot access the file, we cannot create a map,
// so we do not have to free it 
int	**create_map_from_file(char *path,
	t_caption *caption, int *flag_error)
{
	int		**map;
	char	*raw;

	raw = read_file(path);
	if (raw == NULL)
	{
		free(raw);
		ft_putstr("File not found \n");
		return (NULL);
	}
	*caption = fill_caption(raw, flag_error);
	map = (int **)malloc(sizeof(int *) * (caption->rows));
	fill_map(map, caption, raw, flag_error);
	free(raw);
	return (map);
}
