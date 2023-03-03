/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnlTesty.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 21:57:30 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 23:19:28 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	main(void)
{
	int fd;
	char *ptr;

	fd = open(testing.txt);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	return (0);
}
