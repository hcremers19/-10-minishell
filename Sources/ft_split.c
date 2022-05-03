/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:24:12 by acaillea          #+#    #+#             */
/*   Updated: 2021/10/16 17:16:49 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Includes/minishell.h"

/* -----------------TEMporaire -->> libft--------------- */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	p = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (0);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (len > (ft_strlen(s) - start - 1))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			str[j++] = s[i];
	str[j] = 0;
	return (str);
}
/* ------------------------------------------------------ */

static int	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			i++;
	}
	if (!s[0])
		count = 0;
	else if (s[i - 1] != c)
		count++;
	return (count);
}

static char	**free_malloc(char **tab, int count)
{
	while (tab[--count])
		free(tab[count]);
	free (tab);
	return (NULL);
}

static char	**ft_word(char *s, char c, char **tab, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < len)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j + 1] != c && s[j + 1])
			j++;
		tab[k] = ft_substr(s, i, j - i + 1);
		if (!tab[k])
			return (free_malloc(tab, k));
		i = j + 1;
		k++;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**t_tab;
	char	**tab;
	char	*new_s;
	size_t	nb_word;

	new_s = (char *)s;
	if (!new_s)
		return (NULL);
	nb_word = word_count(s, c);
	t_tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!t_tab)
		return (NULL);
	tab = ft_word(new_s, c, t_tab, nb_word);
	return (tab);
}

// int	main(int ac, char **av)
// {
// 	int	i;
// 	char	**tab;

// 	(void)ac;
// 	tab = ft_split(av[1], ' ');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%d = %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }