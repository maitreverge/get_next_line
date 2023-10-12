/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:25:13 by flverge           #+#    #+#             */
/*   Updated: 2023/10/12 12:47:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h> // read
# include <stdlib.h> // malloc + free

// Function of gnl
char	*get_next_line(int fd);
char *big_chunk(int fd, char *stash);
char *extract_before_n(char *stash);
char *extract_after_n(char *stash);



// Functions of utils
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(char *s, int c);

#endif
