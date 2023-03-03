/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:46:02 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 12:00:10 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
int		newline_in_buffer(char *buffer);
void	buffer_status (int newline_found, READ_STATUS)
char	*buffering(int fd, char *buffer, size_t BUFFER_SIZE, int *newline);

#endif