/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:22:36 by flverge           #+#    #+#             */
/*   Updated: 2023/10/04 14:37:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // library for the O_RDONLY oepn's flg
#include <stdio.h>

int main(void)
{
	int fd;
	char *master_buffer;

	fd = open("text.txt", O_RDONLY); // O_RDONLY read_only option for openning the file.

	while (1)
	{
		master_buffer = get_next_line(fd);
		if (master_buffer == NULL)
			break;
		printf("%s", master_buffer);
		free(master_buffer);
	}
	close (fd);
}

/*

	! Coller un file descriptor a un int, qu'on balance ensuite a gnl

	? Coller une condition d'arret dans le main
	? Faire boucler gnl, ou bien la faire boucler sur elle-meme ?

*/