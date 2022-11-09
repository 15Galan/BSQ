/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:30 by ernesmar          #+#    #+#             */
/*   Updated: 2022/11/09 02:04:34 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MANAGE_H
# define FILE_MANAGE_H

/**
 *  @brief  Gets the size of a file.
 * 
 * @param path  Path of the file to get the size.
 * 
 * @return  The size of the file; -1 if not readable.
 */
int		calculate_file_size(char *path);

/**
 * @brief  Reads a file.
 * 
 * @param path  Path of the file to read.
 * 
 * @return  The string inside the file; NULL if not readable.
 */
char	*read_file(char *path);

#endif
