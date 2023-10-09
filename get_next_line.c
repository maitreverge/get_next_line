/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/09 12:19:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// This fucntion will take a chunk until it meets a \n 
char 	*big_chunk(int fd)
{
	char *original_buffer;
	char *temp;
	int return_value_read;
	// ! mallocing the real size
	original_buffer = (char *)ft_calloc(BUFFER_SIZE + 1* sizeof(char)); // ? taille correcte
	// original_buffer = (char *)ft_calloc(BUFFER_SIZE* sizeof(char));
	if (!original_buffer)
		return (NULL);
	// ! Etape 1 : prendre du fd tant qu'il n'y a pas de \n
	return_value_read = read(fd, original_buffer, BUFFER_SIZE);
	while (return_value_read > 0 && ft_strchr(temp, '\n') == NULL)
	{
		if (return_value_read < 0)
			return (NULL);
		temp = ft_strjoin(temp, original_buffer);
		return_value_read = read(fd, original_buffer, BUFFER_SIZE);
	}
	// Cas 1 : il n'y a rien dans la stash => simple copie
	// Cas 2 : il y a deja des trucs, donc il faut join le bordel
	free(original_buffer);
	return (temp);
}

char *extract_line(char *stash)
{
	char *temp;
	char *return_line;
	int size;

	// len_stash = ft_strlen(stash);
	return_line = ft_strchr(stash, '\n');
	size = return_line - ft_strlen(stash);
	temp = (char*)ft_calloc(size, sizeof(char) + 1);
	while (*stash != '\n')
	{
		
	}
	
}

char	*get_next_line(int fd)
{
	char	*current_line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// ! Etape 1 : recupere ce qu'il reste de la stash
	stash = big_chunk(fd);
	if (!stash)
		return (NULL);
	current_line = extract_line(stash);


	
	
	return (current_line);
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