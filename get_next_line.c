/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 14:28:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int return_read;
	static char *stash;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Init du malloc du buffer lors de la compilation
	buffer = (char*)ft_calloc(BUFFER_SIZE, 1);
	if (!buffer)
		return (NULL);
	// faire boucler read
	return_read = read(fd, buffer, BUFFER_SIZE);
	if (return_read < 0)
		return (NULL);
	else
	{
		reading_fd(fd, return_read, buffer)
	}
	return (stash);
}

void	reading_fd(int fd, int return_read, char *buffer)
{
	if (return_read == 0)
	{
		
	}
}
