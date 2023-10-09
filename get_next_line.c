/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/09 14:16:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // library for the O_RDONLY open's flg
#include <stdio.h>
#include "get_next_line_utils.c"


// This fucntion will take a chunk until it meets a \n 
char 	*big_chunk(int fd, char *stash)
{
	char *original_buffer;
	// char *temp;
	int return_value_read;

	// temp == NULL;
	// ! mallocing the real size
	original_buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char)); // ? taille correcte
	// original_buffer = (char *)ft_calloc(BUFFER_SIZE* sizeof(char));
	if (!original_buffer)
		return (NULL);
	// ! Etape 1 : prendre du fd tant qu'il n'y a pas de \n
	return_value_read = read(fd, original_buffer, BUFFER_SIZE);
	while (return_value_read > 0 && ft_strchr(stash, '\n') == NULL)
	{
		if (return_value_read < 0)
			return (NULL);
		stash = ft_strjoin(stash, original_buffer);
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
	}
	// Cas 1 : il n'y a rien dans la stash => simple copie
	// Cas 2 : il y a deja des trucs, donc il faut join le bordel
	free(original_buffer);
	return (stash);
}

char *extract_before_n(char *stash)
{
	char *temp;
	char *buffer;
	int size;
	
	size = 0;

	// Calculer l'index jusqu'au \n
	while (stash[size] != '\n')
	{
		size++;
	}
	
	temp = (char*)malloc(size + 1);
	if (!temp)
		return (NULL);
	while (*stash != '\n')
	{
		*temp = *stash;
		temp++;
		stash++;
	}
	temp[size] = '\0';
	buffer = temp;
	free(temp);
	return (buffer);
}

char *extract_after_n(char *stash)
{
	char *temp;
	char *buffer;
	int i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	temp = (char *)malloc(ft_strlen(stash) - i);
	if (!temp)
		return (NULL);
	while (stash)
	{
		stash[i] = *temp;
		i++;
		temp++;
	}
	buffer = temp;
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
		free(master_buffer);
	}
	close (fd);
}

/*
! Stategie 1
prends un gros bloc sa grand-mere

decouper le gros bloc en deux parties
1 - Un buffer de la taille de la merde a retenir => line
2 - le reste dans un static buffer et ouais mon gars

! Strat 2 
Garder deux buffers, avec une stash et un buffer init au size en fonction de la compilation
1 => Deload le buff dans la stash, et je faire en bouclant la fonction read
2 => Se garder un troisiemme buffer pour faire un ping-pong entre ce dernier et la stash
? Comment malloc la bonne taille, sachant que ca peut varier de 1 a bcp sa mere


! Strat 3 :
Liste chainnees mdr non merci

! Start 4 :

*/