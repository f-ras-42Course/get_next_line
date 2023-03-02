/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/02 23:48:53 by fras          ########   odam.nl         */
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
	char		buffer[BUFFER_SIZE];
	static char	*storage[OPEN_MAX];
	char		*line;
	size_t		STORAGE_SIZE;
	int			newline_position;

	// STORAGE_SIZE = 64;
	// storage = malloc(STORAGE_SIZE * sizeof(char));
	storage[fd] = buffering(fd, &buffer, BUFFER_SIZE);
	while ()
	{
		savebuffer()
		//Save to Storage -> Rebuffer -> Enough storage? ->
		// Save to storage -> else realloc untill enough storage -> save to storage. 
	}
	if (newline_position >= STORAGE_SIZE)
	{
		
	}
	saveline(buffer, line, newline_position);
}

char	*buffering(int fd, char *buffer, size_t BUFFER_SIZE)
{
	int 	newline;
	size_t	READ_STATUS;
	size_t	size;
	size_t	previous_size;
	char	*storage;

	newline = 0;
	size = 0;
	previous_size = 0;
	storage = NULL;
	READ_STATUS = read(fd, buffer, BUFFER_SIZE);
	while (!newline && !READ_STATUS <= 0)
	{
		size += READ_STATUS;
		newline = newline_checker(buffer, BUFFER_SIZE);
		savebuffer(&storage, buffer, size, previous_size);
		previous_size = size;
		READ_STATUS = read(fd, buffer, BUFFER_SIZE);
	}
	if (READ_STATUS == -1)
		return (-1);
	return (storage);
}

void savebuffer(char **storage, char *buffer, size_t size, size_t previous_size)
{
	char	*line;
	char	*backup;
	size_t	i;
	size_t	j;

	i = 0;
	if (!previous_size)
	{
		*storage = malloc(size * sizeof(char));
		while (i < size)
			storage[i] = buffer[i++];
		return;
	}
	backup = malloc(previous_size * sizeof(char));
	while (i < previous_size)
		backup[i] = *storage[i++];
	i = 0;
	j = 0;
	free (*storage);
	storage = malloc(size * sizeof(char));
	while (i < previous_size)
		storage[i] = backup[i++];
	while (i < size)
		storage[i++] = buffer[j++]; //todo for tomorrow: eventually create way to immediately return the allocated line.
									//-- Save last couple of characters in storage
	return;
}


int	newline_checker(char *search, size_t BUFFER_SIZE)
{
	size_t	i;

	while (i <= BUFFER_SIZE)
	{
		if (search[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}


void	buffer_status (int newline, int READ_STATUS, size_t size)
{
	if
}

void saveline(char *buffer, char *dest, int newline_pos)
{
	int i;

	while (buffer[i] != '\n')
}
