/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:22:36 by flverge           #+#    #+#             */
/*   Updated: 2023/10/17 12:46:10 by flverge          ###   ########.fr       */
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
	displayTestSeparator("TEST WITHOUT BUFFER SIZE", 33);
	bn();
	heading(1);
	
	printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Sagittis aliquam malesuada bibendum arcu vitae. Semper auctor neque vitae tempus quam pellentesque nec nam. Enim eu turpis egestas pretium aenean. Ac turpis egestas integer eget. Adipiscing elit pellentesque habitant morbi tristique senectus et. Sapien faucibus et molestie ac feugiat sed lectus. Molestie a iaculis at erat pellentesque. Amet facilisis magna etiam tempor orci eu. Viverra tellus in hac habitasse platea dictumst vestibulum rhoncus. Sit amet consectetur adipiscing elit pellentesque habitant morbi tristique senectus. Lacus luctus accumsan tortor posuere ac ut consequat semper viverra. Nullam vehicula ipsum a arcu cursus vitae congue mauris rhoncus. Sit amet dictum sit amet./n/n");
	printf("Viverra aliquet eget sit amet tellus cras adipiscing. Lacinia at quis risus sed vulputate. Malesuada fames ac turpis egestas sed. Tincidunt lobortis feugiat vivamus at augue eget. Ipsum faucibus vitae aliquet nec ullamcorper sit. Eget egestas purus viverra accumsan in nisl. Convallis a cras semper auctor neque vitae tempus. Quis vel eros donec ac odio tempor. Amet mauris commodo quis imperdiet. Vitae semper quis lectus nulla at volutpat diam ut. Vitae justo eget magna fermentum iaculis eu non.\n\n");
	printf("Adipiscing at in tellus integer feugiat. Praesent elementum facilisis leo vel fringilla est. Ultricies integer quis auctor elit sed vulputate. Adipiscing elit duis tristique sollicitudin nibh sit amet commodo. Viverra accumsan in nisl nisi. Habitant morbi tristique senectus et netus et malesuada fames. Consectetur purus ut faucibus pulvinar elementum integer enim. Turpis massa sed elementum tempus egestas sed sed. Sem viverra aliquet eget sit amet tellus. Dictum sit amet justo donec. Quis hendrerit dolor magna eget est lorem ipsum. Eu facilisis sed odio morbi quis commodo odio aenean sed.");
	

	int fd;
	char *master_buffer;
	fd = open("file_tests/test_3.txt", O_RDONLY);
	
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