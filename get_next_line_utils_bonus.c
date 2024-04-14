#include "get_next_line_bonus.h"

size_t	ft_strlen(char *afll)
{
	size_t	i;

	i = 0;
	if (afll == NULL)
		return (0);
	while (afll[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *fp, char *tba)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char) * (ft_strlen(fp)
				+ ft_strlen(tba) + 1));
	if (!arr)
		return (NULL);
	while (fp && fp[i])
	{
		arr[i] = fp[i];
		i++;
	}
	while (tba && *tba)
		arr[i++] = *tba++;
	arr[i] = '\0';
	free(fp);
	return (arr);
}
char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}
char* ft_strcpy(char *dest, char *src) {
    int i = 0;

    if (!dest || !src)
        return NULL;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
