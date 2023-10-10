/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/10 16:21:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // library for the O_RDONLY open's flg
#include <stdio.h>
#include "get_next_line_utils.c"


char 	*big_chunk(int fd, char *stash)
{
	char *original_buffer;
	int return_value_read;

	original_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); // ? taille correcte
	if (!original_buffer)
		return (NULL);
	return_value_read = 1;
	while (return_value_read > 0 && (ft_strchr(stash, '\n') == NULL)) // \0
	{
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
		if (return_value_read < 0)
		{
			free(original_buffer);
			return (NULL);
		}
		if (!(return_value_read < BUFFER_SIZE))
			stash = ft_strjoin(stash, original_buffer);
	}
	free(original_buffer);
	return (stash);
}

char *extract_before_n(char *stash)
{
	char *temp;
	char *buffer;
	int size;
	int i;
	
	size = 0;
	i = 0;
	
	while (stash[size] != '\n')
		size++;
		
	temp = (char*)malloc(size + 2);
	if (!temp)
		return (NULL);
	
	while (stash[i] != '\n')
	{
		temp[i] = stash[i];
		i++;
	}
	temp[size] = '\n';
	temp[size + 1] = '\0';

	buffer = malloc(ft_strlen(temp));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, temp, ft_strlen(temp));
	free(temp);
	return (buffer);
}

char *extract_after_n(char *stash)
{
	char	*temp;
	char *buffer;
	int		i;
	int		j;

	i = 0; // ! gros doute la dessus
	j = 0;
	while (stash[i] != '\n')
		i++;
	temp = (char *)ft_calloc((ft_strlen(stash) - i) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (stash[i] != '\0')
	{
		temp[j] = stash[i + 1];
		i++;
		j++;
	}
	// temp[j + 1] = '\0'; // ne sert a rien car deja calloc
	buffer = ft_calloc(ft_strlen(temp), sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, temp, ft_strlen(temp));
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*current_line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// ! Etape 1 : recupere ce qu'il reste de la stash
	
	stash = big_chunk(fd, stash);
	if (!stash)
		return (NULL);
		
	current_line = extract_before_n(stash);
	if (!current_line)
		return (NULL);
	
	stash = extract_after_n(stash);
	if (!stash)
		return (NULL);	
	
	return (current_line);
}

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
		// if(master_buffer)
		// 	free(master_buffer);
	}
	if(master_buffer)
		free(master_buffer);
	// free(master_buffer);
	close (fd);
}
