/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 21:08:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*Note to self:
To handle multiple file descriptors, I am going to use a double array. First dimension is OPEN_MAX. Then I use the fd value to call the specific pointer ( [fd] ).
Like:
static char	*storage[OPEN_MAX];
pointer = storage[fd];
*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	char		buffer[BUFFER_SIZE];
	char		*storage;
	char		*line;
	size_t		size;

	size = buffering(buffer, storage, fd, BUFFER_SIZE);
	line = extract_line(storage, leftover[fd], size);
}

char *extract_line(char *source, char *leftover, size_t size)
{
	char	*line;
	size_t	newline_position;

	newline_position = newline_checker(source, size);
	if (!newline_position)
	{
		leftover = 0;
		return (source);
	}
	line = malloc((newline_position + 1) * sizeof(char))
	to_string_alloc()
}

size_t	buffering(char *buffer, char *dest, int fd, size_t BUFFER_SIZE)
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
	return (size);
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