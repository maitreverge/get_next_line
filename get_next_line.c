/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 10:39:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int return_read;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Init du malloc du buffer lors de la compilation
	buffer = (char*)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	// Premiere lecture
	return_read = reading_fd(buffer, fd);
	if (return_read == -1)
		return (NULL);
	
	
	
	
	
}

int reading_fd(char *buffer, int fd)
{
	int i;
	i = read(fd, &buffer, BUFFER_SIZE);
	return (i);
}

/*
	! Etape 0 : creer un void *buffer dans lequel on va pouvoir turbo stocker 
	! Etape 1 : avoir acces au fd pour pouvoir faire tourner la fonction read 

	? Comment faire passer l'argument -D BUFFER_SIZE=42 directement dans le prog ?
	? Print ce flag de compilation dans un define du fichier header / Coller ce flag cash dans
	? une variable static du prog

	! Etape 2 : Choix de l'algo
	* CHOIX 1 ==> Liste chainees
	pour + de perfs. Importer les fonctions de la libft pour ajouter / 
	rejouer les nodes pour recommencer a imprimer sur stdout le bon truc

*/
