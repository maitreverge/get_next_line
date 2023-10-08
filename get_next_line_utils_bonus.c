/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:21:06 by nope              #+#    #+#             */
/*   Updated: 2023/10/08 10:12:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	int		len_s1;
	int		len_s2;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total_len = len_s1 + len_s2 + 1;
	buffer = (char *)ft_calloc(total_len, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	ft_memcpy(&buffer[len_s1], s2, len_s2);
	buffer[len_s1 + len_s2] = '\0';
	return (buffer);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*buffer;

	buffer = malloc(size * count);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)buffer)[i] = 0;
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

char	*ft_strchr(const char *s, int c)
{
	char			*p_s;
	unsigned char	uc_c;

	p_s = ((char *)s);
	uc_c = ((unsigned char)c);
	while (*p_s != '\0')
	{
		if (*p_s == uc_c)
			return (p_s);
		p_s++;
	}
	if (uc_c == '\0')
		return (p_s);
	else
		return (NULL);
}
/*
strchr va rechercher dans un buffer s la presence du char c
(qui est en realite un int pour des soucis de
compatibilite)

*/