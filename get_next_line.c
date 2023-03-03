/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 23:12:03 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		buffer[BUFFER_SIZE];
	char		*storage;
	char		*line;
	size_t		size;

	size = buffering(buffer, storage, fd, BUFFER_SIZE);
	if (size <= 0)
		return (NULL);
	line = extract_line(storage, leftover[fd], size);
	return (line);
}

size_t	buffering(char *buffer, char *dest, int fd, size_t buffer_size)
{
	size_t	READ_STATUS;
	size_t	size;
	size_t	prev_size;
	size_t	*newline

	size = 0;
	prev_size = 0;
	READ_STATUS = read(fd, buffer, BUFFER_SIZE);
	while (!newline && !READ_STATUS <= 0)
	{
		size += READ_STATUS;
		newline = newline_checker(buffer, size);
		if(!save_buffer(buffer, dest, prev_size, size))
			return(0);
		prev_size = size;
		READ_STATUS = read(fd, buffer, size);
	}
	return (size);
}

char	*save_buffer(char *buffer, char *dest, size_t prev_size, size_t size)
{
	if (!prev_size)
		return(to_string_alloc(buffer, dest, size));
	return(to_string_realloc(buffer, dest, size));
}


char	*extract_line(char *source, char *leftover, size_t size)
{
	char	*line;
	size_t	newline_pos;

	newline_pos = newline_checker(source, size);
	if (!newline_pos)
	{
		leftover = 0;
		return (source);
	}
	to_string_alloc(source, line, newline_pos);
	to_string_alloc(source[newline_pos], leftover, size - newline_pos);
	return (line);
}
