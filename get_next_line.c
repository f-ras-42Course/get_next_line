/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 14:00:31 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		*storage;
	size_t		size;

	if(!(storage = malloc(0)))
		return (NULL);
	if (!(size = buffering(&storage, fd)))
		return (NULL);
	return (extract_line(storage, &leftover[fd], size));
}

size_t	buffering(char **dest, int fd)
{
	char	buffer[BUFFER_SIZE];
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
			if (!(*dest = save_string_alloc(buffer, size)))
				return(0);
		}
		else
		{
			if (!(*dest = save_string_realloc(buffer, *dest, size)))
				return(0);
		}
	}
	if (READ_STATUS == -1)
		return (0);
	return (size);
}

char	*extract_line(char *source, char **leftover, size_t size)
{
	char	*line;
	size_t	newline_pos;

	if (!(newline_pos = newline_checker(source, size)))
	{
		leftover = 0;
		return (source);
	}
	line = save_string_alloc(source, newline_pos);
	*leftover = save_string_alloc(source + newline_pos, size - newline_pos); // need to free leftofver.
	return (line);
}
