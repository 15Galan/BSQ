/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernesmar <ernesmar@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:30 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/08 16:33:29 by ernesmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGE_H
# define FILE_MANAGE_H

/*
 * @param path of file to calculate size
 *
 * @return size of file in path or -1 if not readable
 */
int		calculate_file_size(char *path);

/*
 * @param path of file to read
 *
 * @return string inside the file in path or NULL if not readable
 */
char	*read_file(char *path);

#endif
