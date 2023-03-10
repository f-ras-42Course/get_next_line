/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/09 12:25:06 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	leftover[OPEN_MAX][BUFFER_SIZE];
	char		*storage;
	char		*line;

	if (!(storage = buffering(fd)))
	{
		if (*leftover[fd])
			return (extract_line(leftover[fd], leftover[fd]));
		return (NULL);
	}
	line = extract_line(storage, leftover[fd]);
	free(storage);
	return (line);
}

char	*buffering(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*stored_read;
	int		bytes_read;
	size_t	size;
	size_t	newline;

	size = 0;
	newline = 0;
	while (!newline && ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		size += bytes_read;
		newline = newline_checker(buffer, size);
		if (size == (size_t)bytes_read)
		{
			if (!(stored_read = save_alloc_string(buffer, size)))
				return(NULL);
		}
		else
		{
			if (!(stored_read = save_string_realloc(buffer, stored_read, size)))
				return(NULL);
		}
	}
	if ((bytes_read <= 0 && size == 0) || bytes_read == -1)
		return (NULL);
	return (stored_read);
}

char	*extract_line(char *source, char *leftover)
{
	char	*line;
	size_t	newline_pos;
	size_t	leftover_size;

	leftover_size = 0;
	newline_pos = newline_checker(source, 0);
	if (leftover && (source != leftover))
	{

		while (leftover[leftover_size])
			leftover_size++;
		line = save_alloc_string(leftover, leftover_size);
		line = save_string_realloc(source, line, leftover_size + newline_pos);
	}
	else
		line = save_alloc_string(source, newline_pos);
	copy_string(leftover, &source[newline_pos]);
	return (line);
}
