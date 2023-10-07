/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 14:33:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int return_read;
	static char *stash;
	char	*original_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Init du malloc du buffer lors de la compilation
	original_buffer = (char*)ft_calloc(BUFFER_SIZE, 1);
	if (!original_buffer)
		return (NULL);
	// faire boucler read
	return_read = read(fd, original_buffer, BUFFER_SIZE);
	if (return_read < 0)
		return (NULL);
	else
	{
		reading_fd(fd, return_read, original_buffer)
	}
	return (stash);
}

void	reading_fd(int fd, int return_read, char *original_buffer)
{
	char buff_size1[1];
	if (return_read == 0)
	{
		return (ft_strjoin(original_buffer, buff_size1));
	}
}
