/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:22:36 by flverge           #+#    #+#             */
/*   Updated: 2023/10/17 13:31:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h> // library for the O_RDONLY oepn's flg
#include <stdio.h>
#include <string.h>

void displayTestSeparator(const char *text, int colorCode)
{
    int separatorLength = 38;  // Total length of the separator line
    int textLength = strlen(text);
    int paddingLength = separatorLength - textLength;
    int leftPadding = paddingLength / 2;
    int rightPadding = paddingLength - leftPadding;

    printf("\033[%dm\n", colorCode);  // Set the desired text color
    printf("  ///////////////////////////////////////////\n");
    printf(" //%*s%s%*s //\n", leftPadding, "", text, rightPadding, "");
    printf("///////////////////////////////////////////\n");
    printf("\033[0m\n");  // Reset text color
}

void	bn(void)
{
	printf("\n");
}

void	heading(int i)
{
	if (i == 1)
	{
		printf("\033[32;1mEXPECTED_RESULT\033[0m\n");
		return ;
	}
	printf("\033[91;1mGET_NEXT_LINE_RESULT\033[0m\n");
}

int main(void)
{
	displayTestSeparator("TEST BUF SIZE = -42", 96);
	bn();
	heading(1);
	printf("");

	int fd;
	char *master_buffer;
	fd = open("file_tests/test_8.txt", O_RDONLY);
	
	heading(2);
	while (1)
	{
		master_buffer = get_next_line(fd);
		if (master_buffer == NULL)
			break;
		printf("%s", master_buffer);
		free(master_buffer);
	}
	if (master_buffer)
		free(master_buffer);
	close (fd);
}