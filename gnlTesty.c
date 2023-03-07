/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnlTesty.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 21:57:30 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 08:45:14 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *ptr;

	fd = open("testing.txt", O_RDONLY);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	return (0);
}
