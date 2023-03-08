/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/08 09:02:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		*storage;

	if (!(storage = buffering(fd)))
		return (NULL);
	return (extract_line(storage, &leftover[fd]));
}

char	*buffering(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*stored_read;
	int		READ_STATUS;
	size_t	size;
	size_t	newline;

	size = 0;
	newline = 0;
	while (!newline && ((READ_STATUS = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		size += READ_STATUS;
		newline = newline_checker(buffer, size);
		if (size == (size_t)READ_STATUS)
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
	if (READ_STATUS == -1)
		return (NULL);
	return (stored_read);
}

char	*extract_line(char *source, char **leftover)
{
	char	storage[BUFFER_SIZE];
	char	*line;
	size_t	newline_pos;

	if (!(newline_pos = newline_checker(source, 0)))
	{
		*leftover = NULL;
		return (source);
	}
	line = save_alloc_string(source, newline_pos);
	*leftover = copy_string(storage, source + newline_pos);
	free(source);
	return (line);
}
