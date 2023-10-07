/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 16:06:49 by flverge          ###   ########.fr       */
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
	if (stash)
		free(stash);
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

char	*reading_fd(int fd, int return_read, char *original_buffer)
{
	static char *stash;
	
	// presence de \n
	if (check_endofline(original_buffer) == 1)
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

int check_endofile(char *original_buffer)
{
	while (original_buffer)
	{
		if (*original_buffer == '\n')
			return (1);
		*original_buffer++;
	}
	return (0);
}
