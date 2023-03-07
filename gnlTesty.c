/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnlTesty.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 21:57:30 by fras          #+#    #+#                 */
/*   Updated: 2023/03/07 09:53:03 by fras          ########   odam.nl         */
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
	if (fd == -1)
	{
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully\n");
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	close(fd);
	return (0);
}
