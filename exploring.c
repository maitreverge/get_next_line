#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // library for the O_RDONLY open's flg
#include "get_next_line_utils.c"


char *big_chunk(int fd, char *stash)
{
	char *temp;
	int	read_return;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); // Copie avec un \0
	if (!temp)
		return 0;
	read_return = 1;
	while (ft_strchr(stash, '\n') == NULL && read_return != 0)
	{
		read_return = read(fd, temp, BUFFER_SIZE);
		if (read_return == 0) // securite de lecture
		{
			stash[ft_strlen(stash)] = '\0';
			break ;
		}
		if (read_return != 0) // ecriture dans la stash tant que 
			stash = ft_strjoin(stash, temp);
	}
	free(temp);
	return (stash);
}

char *	extract_before_n(char *stash)
{
	char *temp;
	size_t i;

	i = 0;
	// ! Etape 1 : Prendre l'index jusqu'au \n
	while (stash[i] != '\n' && stash[i] != '\0') // deuxieme condition pour la derniere ligne sans \n
		i++;
	temp = ft_calloc((i + 2), sizeof(char)); // + 2 pour rajouter un \n et un \0
	if (!temp)
		return (NULL);
	// ! ETAPE 2 : Copier stash dans temp
	ft_memcpy(temp, stash, i);
	// temp[i] = '\n'; // MODIF
	temp[i] = '\n'; // MODIF
	// ! Pas besoin de [i + 1] = '\0' car calloc
	return (temp);
}

char *extract_after_n(char *stash)
{
	int len_stash;
	int len_until_n;
	char *temp;

	len_until_n = 0;
	if (ft_strchr(stash, '\n'))
	{
		while (stash[len_until_n] != '\n') // LIGNE QUI CASSE LES COUILLES SON ONCLE
			len_until_n++;
	}
	else
	{
		while (stash[len_until_n])
			len_until_n++;		
	}
	len_stash = ft_strlen(stash);
	temp = malloc(len_stash - len_until_n);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, &stash[len_until_n + 1], len_stash - len_until_n);
	return (temp);
}

char *get_next_line(int fd)
{
	char *line;
	static char *stash;
	// int return_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return NULL;
	
	// ! ETAPE 1 : Prendre un gros morceau du fd AVEC un \n dedans
	stash = big_chunk(fd, stash);
	if (!stash)
		return (NULL); // condition qui pete le retour de line a la derniere iteration
	
	// ! ETAPE 2 : Decouper stash jusqu'a le \n et le renvoyer dans char *line
	line = extract_before_n(stash);
	if (!line)
		return (NULL);

	// ! Etape 3 : decouper stash apres le \n et le garder pour le prochain rappel de gnl
	stash = extract_after_n(stash);
	if (!stash)
		return (NULL);
	
	// ! RETURN VALUE
	return (line);
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
	}
	free(master_buffer);
	close (fd);
}