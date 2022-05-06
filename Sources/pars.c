/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/29 18:07:42 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	else
		return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < ((size_t)dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

/* ---------------------------------------------------- */

static int pars_len(char const *s, int i)
{
	int	stat;
	int	len;

	len = 0;
	stat = 0;
	while (s[i + len] && ((s[i + len] != 9 && s[i + len] != 32) || stat != 0))
	{// 9 = tab, 32 = space
		if (stat == 0 && s[i + len] == 39)// 39 = simple guillemet
			stat = 1;
		else if (stat == 0 && s[i + len] == 34)// 34 = double guillemet
			stat = 2;
		else if ((s[i + len] == 39 || s[i + len] == 34) && stat != 0)
			stat = 0;
		if (stat == 0 && (s[i + len] == 60 || s[i + len] == 62 || s[i + len] == 124))
		{// 60 = plus petit ; 62 = plus grand ; 124 = pipe
			if (s[i + len] == s[i + len + 1])
			{
				if ((stat == 0 && len == 0) || (stat != 0 && len != 0))
					len += 2;
			}
			else
			{
				if ((stat == 0 && len == 0) || (stat != 0 && len != 0))
					len ++;
			}
			break ;
		}
		len++;
	}
	return (len);
}

static int	pars_count(char const *s)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = 0;
	count = 0;

	while (s[i])
	{
		while ((s[i] == 9 || s[i] == 32) && s[i])
			i++;
		len = pars_len(s, i);
		if (len != 0)
			count++;
		i += len;
	}
	return (count);
}

char	**ft_pars_word(char const *s, char **tab, int nb)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	while (j < nb)
	{
		l = 0;
		while (s[i] && (s[i] == 9 || s[i] == 32))
			i++;
		l = pars_len(s, i) + 1;
		tab[j] = (char *)malloc(sizeof(char) * (l + 1));
		if (!tab[j])
			return (NULL);
		ft_strlcpy(tab[j], &s[i], l);
		i += l;
		j++;
	}
	return (tab);
}

char	**ft_pars(char const *s)//, t_data *d)
{
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (pars_count(s) + 1));
	if (!tab)
		return (NULL);
	tab = ft_pars_word(s, tab, pars_count(s));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	tab[pars_count(s)] = 0;
	return (tab);
}

// int main(int ac, char **av)
// {
// 	int 	i;
// 	char	*str;
// 	char	**tab;
	
// 	(void)ac;
// 	i = 0;
// 	str = av[1];
// 	tab = ft_pars(str);
// 	if (!tab)
// 		return (0);
// 	while (tab[i])
// 	{
// 		printf("[%d] %zu = %s\n", i, ft_strlen(tab[i]),tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
