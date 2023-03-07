/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:41 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 08:50:52 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	newline_checker(char *search, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		if (search[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*save_string_alloc(char *src, char *dest, size_t size)
{
	size_t	i;

	i = 0;
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size)
	{
			dest[i] = src[i];
			i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*save_string_realloc(char *src, char *dest, size_t size)
{
	size_t	i;
	size_t	prev_size;

	i = 0;
	if (!(prev_size = reallocate(dest, size)))
		return (NULL);
	while (prev_size < size)
		dest[prev_size++] = src[i++];
	dest[size] = '\0';
	return (dest);
}

size_t	reallocate(char *dest, size_t size)
{
	char 	*backup;
	
	if (!(backup = malloc(size * sizeof(char))))
	{
		free(dest);
		return (0);
	}
	freeing_strcpy(backup, dest);
	if (!(dest = malloc((size + 1) * sizeof(char))))
	{
		free(backup);
		return(0);
	}
	return (freeing_strcpy(dest, backup));
}

size_t	freeing_strcpy(char *dest, char *source)
{
	size_t i;

	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	free(source);
	return (i);
}
