/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/02 22:33:50 by fras          ########   odam.nl         */
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
	if (newline_position >= STORAGE_SIZE)
	{
		
	}
	saveline(buffer, line, newline_position);
}

char	*buffering(int fd, char *buffer, size_t BUFFER_SIZE)
{
	int 	newline_found;
	size_t	READ_STATUS;
	size_t	size;
	size_t	size_previous;
	char	*storage;

	newline_found = 0;
	size = 0;
	size_previous = 0;
	storage = NULL;
	READ_STATUS = read(fd, buffer, BUFFER_SIZE);
	while (!newline_found && !READ_STATUS <= 0)
	{
		size += READ_STATUS;
		newline_found = newline_checker(buffer, BUFFER_SIZE);
		storage = save_buffer(buffer, size, size_previous);
		size_previous = size;
		READ_STATUS = read(fd, buffer, BUFFER_SIZE);
	}
	if (READ_STATUS == -1)
		return (-1);
	return (storage);
}

void save_buffer(char *buffer, size_t size, size_t size_previous)
{
	char	*storage;
	size_t	i;

	if (!size_previous)
	{
		storage = malloc(size * sizeof(char));
		while (i < size)
		{
			
		}
	}
}


int	newline_checker(char *search, size_t BUFFER_SIZE)
{
	size_t	i;

	while (i <= BUFFER_SIZE)
	{
		if (search[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


void	buffer_status (int newline_found, int READ_STATUS, size_t size)
{
	if
}

void saveline(char *buffer, char *dest, int newline_pos)
{
	int i;

	while (buffer[i] != '\n')
}
