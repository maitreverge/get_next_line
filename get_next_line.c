/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 16:25:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int return_read;
	// static char *stash;
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
	// reading_fd(fd, return_read, original_buffer, stash);
	return (reading_fd(fd, return_read, original_buffer));
	// return (stash);
}

int check_endofile(char *original_buffer)
{
	int i = 0;
	while (original_buffer[i])
	{
		if (original_buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*reading_fd(int fd, int return_read, char *original_buffer)
{
	static char *stash;
	
	// if (stash)
	// 	free(stash);
		// presence de \n
	if (check_endofile(original_buffer) == 1)
		return (ft_strjoin(stash, original_buffer));
	else
	{
		while (check_endofile(original_buffer) == 0 && return_read > 0)
		{
			stash = ft_strjoin(stash, original_buffer); // deload dans la stash
			free(original_buffer);
			return_read = read(fd, original_buffer, BUFFER_SIZE);
		}
	}
	return (stash);

}

