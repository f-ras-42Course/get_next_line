/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:46:02 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 14:00:58 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
size_t	buffering(char **dest, int fd);
char	*extract_line(char *source, char **leftover, size_t size);
size_t	newline_checker(char *search, size_t size);
char	*save_string_alloc(char *source, size_t size);
char	*save_string_realloc(char *source, char *dest, size_t size);
size_t	freeing_strcpy(char *dest, char *source);
size_t	reallocate(char *dest, size_t size);

#endif