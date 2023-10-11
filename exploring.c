#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // library for the O_RDONLY open's flg
#include "get_next_line_utils.c"


char *big_chunk(int fd, char *stash)
{
	char *temp;
	char *buffer;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return NULL;
}

char *get_next_line(int fd)
{
	char *line;
	static char *stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return NULL;
	
	// ! ETAPE 1 : Prendre un gros morceau du fd AVEC un \n dedans
	stash = big_chuck(fd, stash);
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