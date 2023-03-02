/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:53 by fras          #+#    #+#                 */
/*   Updated: 2023/03/02 19:13:21 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer[BUFFER_SIZE];
	char	*storage;
	char	*line;
	size_t	STORAGE_SIZE;
	int		newline_position;

	STORAGE_SIZE = 64;
	storage = malloc(STORAGE_SIZE * sizeof(char));
	buffering(fd, &buffer, BUFFER_SIZE)
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

int	buffering(int fd, char **buffer, size_t BUFFER_SIZE)
{
	int newline_found;
	int	READ_STATUS;
	int	total_bytes;
	int i;

	newline_found = 0;
	total_bytes = 0;
	i = 0;
	while(!newline_found && !READ_STATUS <= 0)
	{
		READ_STATUS = read(fd, buffer, BUFFER_SIZE);
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				newline_found = 1;
			i++;
		}
		total_bytes += i;
		i = 0;
	}
	return (0);
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
