/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nope <nope@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/12 19:56:32 by nope             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h> // read
#include <stdlib.h> // malloc + free
#include <fcntl.h> // library for the O_RDONLY oepn's flg
#include <stdio.h>

#include "get_next_line_utils.c"

char 	*big_chunk(int fd, char *stash)
{
	char *original_buffer;
	int return_value_read;

	original_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!original_buffer)
		return (NULL);
	return_value_read = 1;
	while (return_value_read != 0 && ft_strchr(stash, '\n') == NULL) // \0
	{
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
		// bloc qui casse les couilles sa mere
		if (return_value_read <= 0)
			break ;
		if (return_value_read != 0)
			stash = ft_strjoin(stash, original_buffer);
	}
	free(original_buffer);
	return (stash);
}

char *extract_before_n(char *stash)
{
	char *temp;
	// char *buffer;
	int size;
	int i;
	
	size = 0;
	i = 0;
	// while (stash[size] != '\n' && stash[size] != '\0')
	while (stash[size] != '\n') // invalid arguments for the last line
		size++;
	temp = (char*)malloc((size + 1) * sizeof(char)); // NE SURTOUT PAS CALLOC ICI
	if (!temp)
		return (NULL);
	while (stash[i] != '\n') // invalid argument for the last line
	{
		temp[i] = stash[i];
		i++;
	}
	/*
	segfault ici
	*/
	// temp[size] = '\n';
	temp[size] = '\0';

	// if (!buffer)
	// 	return (NULL);
	// ft_memcpy(buffer, temp, ft_strlen(temp));
	// free(temp);
	return (temp);
}

char *extract_after_n(char *stash)
{
	char	*temp;
	// char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// while (stash[i] != '\n' && stash[i] != '\0')
	while (stash[i] != '\n')
		i++;
	temp = malloc(ft_strlen(stash) - i + 1); // alloue la taille exacte restante
	if (!temp)
		return (NULL);
	// while (stash[i] != '\0' && stash[i] != '\n')
	while (stash[i] != '\0')
	{
		temp[j] = stash[i + 1];
		i++;
		j++;
	}
	// buffer = ft_strdup(temp);
	// if (!buffer)
	// 	return (NULL);
	// ft_memcpy(buffer, temp, ft_strlen(temp));
	// !!!!!!!!!!!!!!!!!! ET TA GRAND MERE LE LEAK !!!!!!!!!!!!!!!!!!!!!!!
	// free(temp);
	return (temp);
}

char	*get_next_line(int fd)
{
	char	*current_line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = big_chunk(fd, stash);
	if (!stash)
		return (NULL);
	current_line = extract_before_n(stash);
	stash = extract_after_n(stash);
	return (current_line);
}

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
