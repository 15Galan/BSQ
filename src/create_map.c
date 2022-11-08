/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:03:11 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 21:33:11 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_processing.h"
#include "caption.h"
#include "ft_str.h"
#include "file_manage.h"

#include <stdlib.h>

int	calculate_rows(char *raw)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (raw[i] != '\n')
		i++;
	i++;
	while (raw[i++] != '\n')
		count++;
	return (count);
}

//raw is the raw text in the file or the stdin in the form
// NCCC ...(next part of the map);
// where N is number of lines
// C is a character meaning something in the map
// TODO: chech ft_is_printable of caption
t_caption	fill_caption(char *raw, int *flag_error)
{
	t_caption	new_caption;
	int			displacement;

	displacement = get_base(atoi(raw));
	new_caption.num_rows = atoi(raw);
	new_caption.num_columns = calculate_rows(raw);
	new_caption.empty = raw[displacement + 0];
	new_caption.obstacle = raw[displacement + 1];
	new_caption.full = raw[displacement + 2];
	if (raw[displacement + 4] != '\n')
		*flag_error = 1;
	else if (ft_is_printable(new_caption.empty) == 0)
		*flag_error = 1;
	else if (ft_is_printable(new_caption.obstacle) == 0)
		*flag_error = 1;
	else if (ft_is_printable(new_caption.full) == 0)
		*flag_error = 1;
	else if (new_caption.empty != new_caption.obstacle)
		*flag_error = 1;
	else if (new_caption.obstacle != new_caption.full)
		*flag_error = 1;
	else if (new_caption.full != new_caption.empty)
		*flag_error = 1;
	return (new_caption);
}

int	elem_from_caption(char element, t_caption caption)
{
	if (element == caption.empty)
		return (0);
	else if (element == caption.obstacle)
		return (1);
	else
		return (-1);
}

//fill the maps and check if is correct.
//if is not correct, error = -1
//
//*
//if(raw[displacement + 4] != '\n')
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
	while (raw[(++raw_pos) + 1] != '\0' && j < caption->num_rows)
	{
		if (raw[raw_pos] == '\n')
		{
			map[++j] = (int *)malloc(sizeof(int) * caption->num_columns);
			*flag_error = (i != caption->num_columns && j - 1 != 0);
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

//if we cannot access the file, we cannot create a map,
//so we do not have to free it 
int	**create_map_from_file(char *path,
	t_caption *caption, int *flag_error)
{
	int		**map;
	char	*raw;

	raw = read_file(path);
	if (raw == NULL)
	{
		ft_putstr("File not found \n");
		return (NULL);
	}
	*caption = fill_caption(raw, flag_error);
	map = (int **)malloc(sizeof(int *) * (caption->num_rows));
	fill_map(map, caption, raw, flag_error);
	free(raw);
	return (map);
}
