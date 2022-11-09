/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:23:29 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 14:31:09 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	calculate_file_size(char *path)
{
	int		fd;
	char	*temp_buffer;
	int		increase;
	int		total_size;
	int		attempt;

	attempt = 64;
	increase = 64;
	total_size = 0;
	temp_buffer = (char *)malloc(sizeof(char *) * increase);
	fd = open(path, O_RDONLY);
	if (temp_buffer == NULL || fd == -1)
	{
		close(fd);
		return (-1);
	}
	while (attempt != 0)
	{
		attempt = read(fd, temp_buffer, increase);
		if (attempt != 0)
			total_size += increase;
	}
	close(fd);
	free(temp_buffer);
	return (total_size);
}

char	*read_file(char *path)
{
	int		file_size;
	int		fd;
	char	*buffer;

	file_size = calculate_file_size(path);
	if (file_size <= 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	buffer = (char *)malloc(sizeof(char *) * file_size);
	if (fd == -1 || buffer == NULL)
	{
		close(fd);
		return (NULL);
	}
	read(fd, buffer, file_size);
	close(fd);
	return (buffer);
}
