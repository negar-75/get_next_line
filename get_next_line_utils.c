#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (s == NULL)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!arr)
		return (NULL);
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}

char*	ft_strcpy(char *dest, char *src) 
{
    int i;

	i = 0;
	if (!dest || !src)
		return NULL;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
