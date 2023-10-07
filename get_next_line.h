/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:25:13 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 16:24:42 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5

# include <unistd.h> // read
# include <stdlib.h> // malloc + free

// Function of gnl
char	*get_next_line(int fd);
char	*reading_fd(int fd, int return_read, char *original_buffer);
int check_endofile(char *original_buffer);


// Functions of utils
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);





#endif
