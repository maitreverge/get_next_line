/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:25:22 by flverge           #+#    #+#             */
/*   Updated: 2023/10/11 13:46:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		len_s1;
	int		len_s2;
	int		total_len;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	// len_s2 = ft_strlen(s2);
	len_s2 = BUFFER_SIZE;
	total_len = len_s1 + len_s2 + 1;
	buffer = (char *)ft_calloc(total_len, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	ft_memcpy(&buffer[len_s1], s2, len_s2);
	buffer[len_s1 + len_s2] = '\0';
	free(s1);
	return (buffer);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*buffer;

	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
strchr va rechercher dans un buffer s la presence du char c
(qui est en realite un int pour des soucis de
compatibilite)

If the character c is found in the string s, the function returns a pointer to the first occurrence of c in s.
If the character c is not found in the string s, the function returns NULL.

*/