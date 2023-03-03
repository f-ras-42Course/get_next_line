/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 15:35:45 by fras          ########   odam.nl         */
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
	char		buffer[size];
	static char	*leftover[OPEN_MAX];
	char		*saved_read;
	size_t		saved_read_size;
	char		*line;

	saved_read_size = buffering(saved_read, fd, buffer, BUFFER_SIZE);
	line = extract_line(saved_read, &leftover[fd], saved_read_size);
}

char *extract_line(char *source, char *leftover_chars, size_t size)
{
	size_t newline_position;

	newline_position = newline_checker(source, size);
	if (!newline_position)
		
}

size_t	buffering(char *dest, int fd, char *buffer, size_t BUFFER_SIZE)
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
		save_buffer(dest, buffer, size, prev_size);
		prev_size = size;
		READ_STATUS = read(fd, buffer, size);
	}
	if (READ_STATUS == -1)
		return (-1);
	return (size);
}

size_t	save_buffer(char *dest, char *buffer, size_t size, size_t prev_size)
{
	char	*backup;
	size_t	i;
	size_t	j;

	i = 0;
	if (!prev_size)
	{
		dest = malloc((size + 1) * sizeof(char));
		while (i < size)
			dest[i] = buffer[i++]; // eventually change to allocated_memcpy(dest, buffer, size) -> return value = size
		return (i);
	}
	backup = malloc(prev_size * sizeof(char));
	while (i < prev_size)
		backup[i] = dest[i++];
	i = 0;
	j = 0;
	free (dest);
	storage = malloc((size + 1) * sizeof(char));
	while (i < prev_size)
		storage[i] = backup[i++];
	while (i < size)
		storage[i++] = buffer[j++];
	return (i);
}


int	newline_checker(char *search, size_t size)
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