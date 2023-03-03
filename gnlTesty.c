/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnlTesty.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fras <fras@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 21:57:30 by fras          #+#    #+#                 */
/*   Updated: 2023/03/03 23:04:48 by fras          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;

	fd = open(testing.txt);
	get_next_line(fd);
}
