/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/04 14:54:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_endline(char *str)
{
	while (str)
	{
		if (*str == '\n')
			return (1);
		*str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int		return_read;
	char	*temp_buffer;

	if (fd < 0)
		return (NULL);
	temp_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!temp_buffer)
		return (NULL);
	while (1)
	{
		return_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (return_read <= 0)
		{
			return (NULL);
			break;
		}
		if (check_endline(temp_buffer) == 1)
		{
			// ! Faire qqch du buffer
		}
		free(temp_buffer);
	}
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

	* CHOIX 2 ==> Buffer de gitan, stash
	! Savoir si la stash et le buffer soivent pas etre identiques pour plus de coherence
	! Est-ce authorise ??
	! Est-ce que le realloc a chaque fois va pas taper la stack avec des enormes fichiers

*/
