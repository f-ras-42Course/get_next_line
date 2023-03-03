/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 20:57:16 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[size];
	static char	*leftover[OPEN_MAX];
	char		*saved_read;

	char		*line;

	buffering(saved_read, fd, buffer, BUFFER_SIZE);
	line = extract_line(saved_read, leftover[fd]);
}

char *extract_line(char *source, char *leftover)
{
	char	*line;
	size_t	newline_position;

	newline_position = newline_checker(source, size);
	if (!newline_position)
	{
		source[size] = '\0';
		leftover = 0;
		return (source);
	}
	line = malloc((newline_position + 1) * sizeof(char))
	
}

void	buffering(char *dest, int fd, char *buffer, size_t BUFFER_SIZE)
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
		save_buffer(buffer, dest, prev_size, size);
		prev_size = size;
		READ_STATUS = read(fd, buffer, size);
	}
	if (READ_STATUS == -1)
		return (-1);
	// return (size);
}

void	save_buffer(char *buffer, char *dest, size_t prev_size, size_t size)
{
	if (!prev_size)
		to_string_alloc(buffer, dest, size);
	to_string_realloc(buffer, dest, prev_size, size);
}

void	to_string_alloc(char *src, char *dest, size_t size)
{
	size_t	i;

	i = 0;
	dest = malloc((size + 1) * sizeof(char));
	while (i < size)
			dest[i] = src[i++];
	dest[i] = '\0';
}

void	to_string_realloc(char *src, char *dest, size_t prev_size, size_t size)
{
	char	*backup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	backup = malloc(prev_size * sizeof(char));
	while (i < prev_size)
		backup[i] = dest[i++];
	free (dest);
	dest = malloc((size + 1) * sizeof(char));
	while (i < prev_size)
		dest[i] = backup[i++];
	while (i < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
}

size_t	newline_checker(char *search, size_t size)
{
	size_t	i;

	while (i <= size)
	{
		if (search[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}