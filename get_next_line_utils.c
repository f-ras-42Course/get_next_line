/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:41 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 16:45:41 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	newline_checker(char *search, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (search[i])
		{
			if (search[i] == '\n')
				return (++i);
			i++;
		}
	}
	while (i <= size)
	{
		if (search[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*save_alloc_string(char *src, size_t size)
{
	char	*dest;
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

char	*save_string_realloc(char *source, char *dest, size_t size)
{
	char 	*backup;
	size_t	i;
	size_t	prev_size;

	i = 0;
	prev_size = 0;
	while (dest[prev_size])
		prev_size++;
	if (!(backup = malloc((prev_size + 1) * sizeof(char))))
	{
		free(dest);
		return (0);
	}
	copy_string(backup, dest);
	free(dest);
	if (!(dest = malloc((size + 1) * sizeof(char))))
	{
		free(backup);
		return(0);
	}
	copy_string(dest, backup);
	free(backup);
	while (prev_size < size)
		dest[prev_size++] = source[i++];
	dest[size] = '\0';
	return (dest);
}

char	*copy_string(char *dest, char *source)
{
	size_t i;

	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
