/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:45:41 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 21:19:36 by fras          ########   odam.nl         */
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
