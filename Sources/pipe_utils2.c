#include "../includes/pipe.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	i;
	size_t	j;
	char	*h;

	h = (char *)haystack;
	count = ft_strlen(needle);
	if (!count)
		return (h);
	if ((ft_strlen(haystack) < count) || len < count)
		return (NULL);
	i = 0;
	while (h[i] && i <= len - count)
	{
		j = 0;
		while (needle[j] && (needle [j] == h[i + j]))
			j++;
		if (j == count)
			return (&h[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*d;

	if (!s1 || !s2)
		return (0);
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (0);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = 0;
	return (d);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc((sizeof(char) * (ft_strlen(s1) + 1)));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start - 1))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			str[j++] = s[i];
	str[j] = 0;
	return (str);
}