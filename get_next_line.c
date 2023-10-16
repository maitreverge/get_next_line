/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/16 15:03:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/////////////////////////////

// #include <unistd.h> // read
// #include <stdlib.h> // malloc + free
// #include <fcntl.h> // library for the O_RDONLY open's flg
// #include <stdio.h>
// #include "get_next_line_utils.c"

////////////////////////////

char 	*big_chunk(int fd, char *stash)
{
	char *original_buffer;
	int return_value_read;

	return_value_read = 1;
	original_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char)); // add a \0 
	if (!original_buffer)
		return (NULL);
	while (return_value_read != 0 && ft_strchr(stash, '\n') == NULL)
	{
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
		if (return_value_read == -1)
		{
			free(original_buffer);
			return NULL;
		}
		original_buffer[return_value_read] = '\0';
		stash = ft_strjoin(stash, original_buffer);
	}
	free(original_buffer);
	return (stash);
}

char *extract_before_n(char *stash)
{
	char *temp;
	int size;
	
	size = 0;
	if (!stash[size])
		return NULL;
	while (stash[size] != '\n' && stash[size]) // ! DOUTE
		size++;
	temp = (char*)malloc((size + 2) * sizeof(char)); // NE SURTOUT PAS CALLOC ICI, SINON CA TURBO FOUT LA MERDE POUR LES \0
	if (!temp)
		return (NULL);
	size = 0;
	while (stash[size] != '\n' && stash[size]) // ! DOUTE
	{
		temp[size] = stash[size];
		size++;
	}
	if (stash[size] == '\n')
	{
		temp[size] = stash[size];
		size++;
	}
	
	temp[size] = '\0';
	return (temp);
}

char *extract_after_n(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return NULL;
	}

	
	temp = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char)); // alloue la taille exacte restante
	if (!temp)
		return (NULL);
	
	j = 0;
	i++;
	while (stash[i] != '\0')
	{
		temp[j] = stash[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	
	free(stash);
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

// int main(void)
// {
// 	int fd;
// 	char *master_buffer;

// 	fd = open("text.txt", O_RDONLY);

// 	while (1)
// 	{
// 		master_buffer = get_next_line(fd);
// 		if (master_buffer == NULL)
// 			break;
// 		printf("%s", master_buffer);
// 		free(master_buffer);
// 	}
// 	if (master_buffer)
// 		free(master_buffer);
// 	close (fd);
// }
