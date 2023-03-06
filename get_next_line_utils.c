/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:41 by fras          #+#    #+#                 */
/*   Updated: 2023/03/06 15:19:48 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*save_buffer_alloc(char *src, char *dest, size_t size)
{
	size_t	i;

	i = 0;
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size)
			dest[i] = src[i++];
	dest[i] = '\0';
	return (dest);
}

char	*save_buffer_realloc(char *src, char *dest, size_t size)
{
	size_t	i;
	size_t	prev_size;

	i = 0;
	if (!(prev_size = reallocate(dest, size)))
		return (NULL);
	while (prev_size < size)
		dest[prev_size++] = src[i++];
	dest[size + 1] = '\0';
	return (dest);
}

size_t	reallocate(char *dest, size_t size)
{
	char 	*backup;
	size_t	i;
	size_t	prev_size;

	i = 0;
	if (!(backup = malloc(size * sizeof(char))))
	{
		free(dest);
		return (NULL);
	}
	while (dest[i])
		backup[i] = dest[i++];
	free (dest);
	if (!(dest = malloc((size + 1) * sizeof(char))))
	{
		free(backup);
		return(NULL);
	}
	prev_size = i;
	i = 0;
	while (i < prev_size)
		dest[i] = backup[i++];
	free(backup);
	return (prev_size);
}
