/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/26 18:46:02 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 23:09:59 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

# define BUFFER_SIZE 64

char	*get_next_line(int fd);
size_t	buffering(char *buffer, char *dest, int fd, size_t BUFFER_SIZE);
char	*save_buffer(char *buffer, char *dest, size_t prev_size, size_t size);
char	*extract_line(char *source, char *leftover, size_t size);
size_t	newline_checker(char *search, size_t size);
char	*to_string_alloc(char *src, char *dest, size_t size);
char	*to_string_realloc(char *src, char *dest, size_t size);
char	*reallocate(char *dest, size_t size);


#endif