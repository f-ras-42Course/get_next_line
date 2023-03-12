/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/12 02:05:13 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	leftover[OPEN_MAX][BUFFER_SIZE];
	char		*storage;
	size_t		len;
	size_t		newline_pos;

	len = retrieve_leftover(&storage, leftover[fd]);
	if (!storage)
		return (NULL);
	newline_pos = find_newline(storage, len);
	if (newline_pos)
		return (extract_line(storage, leftover[fd], newline_pos));
	len = buffering(fd, &storage, len);
	if (!storage)
		return (NULL);
	newline_pos = find_newline(storage, len);
	if (newline_pos)
		return (extract_line(storage, leftover[fd], newline_pos));
	if (!*storage)
	{
		free(storage);
		return(NULL);
	}
	return (storage);
}

size_t	retrieve_leftover(char **dest, char *leftover)
{
	size_t	leftover_size;

	leftover_size = 0;
	while (leftover[leftover_size])
		leftover_size++;
	*dest = save_alloc_string(leftover, leftover_size);
	if (!*dest)
		return (0);
	*leftover = '\0';
	return (leftover_size);
}

size_t	buffering(int fd, char **stored_read, size_t old_size)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	size_t	size;
	size_t	newline;

	size = old_size;
	newline = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (!newline && bytes_read > 0)
	{
		size += bytes_read;
		newline = find_newline(buffer, BUFFER_SIZE);
		*stored_read = save_string_realloc(buffer, *stored_read, size);
		if (!*stored_read)
			return (0);
		if (!newline)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		*stored_read = NULL;
		return (0);
	}
	return (size);
}

char	*extract_line(char *source, char *leftover, size_t len)
{
	char	*line;

	sizeof_stringcopy(leftover, &source[len]);
	line = save_alloc_string(source, len);
	free(source);
	return (line);
}
