/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:23:29 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 16:31:01 by ernesmar         ###   ########.fr       */
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
	while (attempt > 0)
	{
		attempt = read(fd, temp_buffer, increase);
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

	fd = open(path, O_RDONLY);
	file_size = calculate_file_size(path);
	buffer = (char *)malloc(sizeof(char *) * file_size);
	if (fd == -1)
	{
		return (NULL);
	}
	read(fd, buffer, file_size);
	close(fd);
	return (buffer);
}
