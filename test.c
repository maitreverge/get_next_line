#include <stdio.h>

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

int main(void)
{
	const char *str = "Hello, World!";
	int ch = 'o';
	char *result = ft_strchr(str, ch);
	printf("The character '%c' is found at position %ld\n", ch, result - str);
}