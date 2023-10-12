/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:22:36 by flverge           #+#    #+#             */
/*   Updated: 2023/10/12 13:53:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // library for the O_RDONLY oepn's flg
#include <stdio.h>

int main(void)
{
	int fd;
	char *master_buffer;

	fd = open("text.txt", O_RDONLY);

	while (1)
	{
		master_buffer = get_next_line(fd);
		if (master_buffer == NULL)
			break;
		printf("%s", master_buffer);
	}
	free(master_buffer);
	close (fd);
}

/*
	How C open() works in OS
Find the existing file on the disk.
Create file table entry.
Set the first unused file descriptor to point to the file table entry.
Return file descriptor used, -1 upon failure.

*/