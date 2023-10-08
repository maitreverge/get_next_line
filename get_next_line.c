/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nope <nope@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:24:42 by flverge           #+#    #+#             */
/*   Updated: 2023/10/08 22:22:04 by nope             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*reset_stash(int fd, char *stash)
{
	char *cleaned_stash;
	char *temp;
	if (stash)
	{
		// remettre au max BUFFER_SIZE au debut de stash
		temp = ft_strchr(stash, '\n');
		cleaned_stash = ft_stjoin()
		
		
	}
	else
		return (NULL);
}                                                                                                                                                                                                                                                                                                                                                                                

char	*get_next_line(int fd, char *current_line)
{
	// int		return_read;
	char	*current_line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// ! Etape 1 : recupere ce qu'il reste de la stash
	stash = reset_stash(fd, stash);
	
	return (current_line);
}

/*
prends un gros bloc sa mere

decouper le gros bloc en deux parties
1 - Un buffer de la taille de la merde a retenir => line
2 - le reste dans un static buffer et ouais mon gars

*/