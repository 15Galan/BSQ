/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:03:11 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 15:03:50 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "caption.h"
#include "ft_str.h"
#include "args_processing.h"


int calculate_file_size(char *path)
{
	int fd;
	char *temp_buffer;
	int increase;
	int total_size;
	int attempt;

	attempt = 64;
	increase = 64;
	total_size = 0;
	temp_buffer = (char *) malloc(sizeof(char *) * increase);
	fd = open(path, O_RDONLY);
	while (attempt > 0)
	{
		attempt = read(fd,temp_buffer,increase);
		total_size += increase;
	}
	close(fd);
	free(temp_buffer);
	return (total_size);
}

int calculate_rows(char *raw)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(raw[i] != '\n')
		i++;
	i++;
	while(raw[i++] != '\n')
		count++;
	return count;
}

//raw is the raw text in the file or the stdin in the form 
// NCCC ...(next part of the map);
// where N is number of lines
// C is a character meaning something in the map
// TODO: chech ft_is_printable of caption
t_caption fill_caption(char *raw, int *flag_error)
{
	t_caption new_caption;
	int displacement;

	displacement = get_base(atoi(raw));
	
	new_caption.num_rows = atoi(raw);
	new_caption.num_columns = calculate_rows(raw);
	new_caption.empty = raw[displacement + 1];
	new_caption.obstacle = raw[displacement + 2];
	new_caption.full = raw[displacement + 3];
	if(raw[displacement + 4] != '\n')
		*flag_error = 1;
	
	if(ft_is_printable(new_caption.empty) == 0 ||
			ft_is_printable(new_caption.obstacle) == 0 ||
			ft_is_printable(new_caption.full) == 0 )
	{
		*flag_error = 1;
	}
	if(new_caption.empty != new_caption.obstacle &&
			new_caption.obstacle != new_caption.full &&
			 new_caption.full != new_caption.empty )
	{
		*flag_error = 1;
	}

	return(new_caption);
}


char *read_file(char *path)
{
	int		file_size;
	int		fd; 
	char	*buffer;

	fd = open(path, O_RDONLY);
	file_size = calculate_file_size(path);
	buffer = (char *)malloc(sizeof(char *) * file_size);
	if(fd == -1)
	{
		return (NULL);
	}
	read(fd, buffer, file_size);
	close(fd);
	return (buffer);
}

int elem_from_caption(char element, t_caption caption)
{
	if(element == caption.empty)
		return (0);
	else if(element == caption.obstacle)
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
void fill_map(int **map, t_caption* caption, char *raw, int *flag_error)
{
	int raw_pos;
	int i;
	int j;

	raw_pos = 0;
	i = 0;
	j = -1;
	while (raw[raw_pos+1] != '\n')
		raw_pos++;
	while(raw[(++raw_pos) + 1]  != '\0' && j <caption->num_rows)  
	{
		if(raw[raw_pos] == '\n' )
		{
			map[++j] = (int *) malloc(sizeof(int) * caption->num_columns);
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

//if we cannot access the file, we cannot create a map, so we do not have to free it
int **create_map_from_file(char *path, t_caption *caption, int *flag_error)
{
	int **map;
	char *raw;

	raw = read_file(path);
	//*size = ft_atoi(raw);
	if(raw == NULL) 
	{
		ft_putstr("File not found \n");
		return (NULL);
	}
	*caption = fill_caption(raw, flag_error);
	map = (int **) malloc(sizeof(int *) * (caption->num_rows));
	fill_map(map, caption, raw, flag_error);
	free(raw);
	return (map);
}
