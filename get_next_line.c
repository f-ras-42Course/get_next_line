/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/02 21:04:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


/*Note to self:
To handle multiple file descriptors, I am going to use a double array. First layer is OPEN_MAX. Then I use the fd to call which [fd] I use.
Like:
static char	*storage[OPEN_MAX];
storage[fd];
But first handle it and make it work with just one file descriptor.
*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer[BUFFER_SIZE];
	static char	*storage;
	char		*line;
	size_t		STORAGE_SIZE;
	int			newline_position;

	STORAGE_SIZE = 64;
	storage = malloc(STORAGE_SIZE * sizeof(char));
	storage = buffering(fd, &buffer, BUFFER_SIZE)
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

size_t	buffering(int fd, char **buffer, size_t BUFFER_SIZE)
{
	int 	newline_found;
	int		READ_STATUS;
	size_t	total_bytes;
	size_t	i;

	newline_found = 0;
	total_bytes = 0;
	i = 0;
	while(!newline_found && !READ_STATUS <= 0)
	{
		READ_STATUS = read(fd, buffer, BUFFER_SIZE);
		while (buffer[i] && !newline_found)
		{
			if (buffer[i] == '\n')
				newline_found = 1;
			i++;
		}
		save_buffer
		total_bytes += READ_STATUS;
		savebuffer
		i = 0;
	}
	return (buffer_status(newline_found, READ_STATUS, total_bytes));
}

void	buffer_status (int newline_found, int READ_STATUS, size_t total_bytes)
{
	if (be)
}

void savebuffer(char *buffer, char *dest, int newline_pos)
{
	int i;

	while (buffer[i] != '\n')
}

void saveline(char *buffer, char *dest, int newline_pos)
{
	int i;

	while (buffer[i] != '\n')
}
