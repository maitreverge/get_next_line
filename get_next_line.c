/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/08 11:47:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_endoline(char *original_buffer)
{
	int i;

	i = 0;
	while (original_buffer[i])
	{
		if (original_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*deload_buffer(char *original_buffer, int return_read, int fd)
{
	static char *stash;
	if (return_read == 0)
		return (NULL);
	while (check_endoline(original_buffer) == 0 && return_read > 0)
	{
		stash = ft_strjoin(stash, original_buffer);
		free(original_buffer);
		return_read = read(fd, original_buffer, BUFFER_SIZE);
	}
	// if (return_read == 0)
	// 	return (NULL);
	if (check_endoline(stash) == 1)
	{
		
	}
	
	return (stash);
}

char	*get_next_line(int fd)
{
	int		return_read;
	char	*original_buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	original_buffer = (char*)ft_calloc(BUFFER_SIZE, 1);
	if (!original_buffer)
		return (NULL);
	return_read = read(fd, original_buffer, BUFFER_SIZE);
	if (return_read < 0)
		return (NULL);
	line = deload_buffer(original_buffer, return_read, fd);
	return (line);
}