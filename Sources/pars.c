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

//#include "../Includes/minishell.h"

/* -----------------TEMporaire -->> libft--------------- */

// #include <stdio.h>
// #include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	count;

// 	count = 0;
// 	while (s[count])
// 		count++;
// 	return (count);
// }

// int	ft_isalpha(int c)
// {
// 	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
// 		return (1);
// 	else
// 		return (0);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	if (dstsize > 0)
// 	{
// 		while (src[i] && i < ((size_t)dstsize - 1))
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = 0;
// 	}
// 	return (ft_strlen(src));
// }

// /* ---------------------------------------------------- */

// // static int check_in(char *s, int j)
// // {
// // 	int	i;
// // 	int	stat;

// // 	i = j;
// // 	stat = 0;
// // 	while (s && s[i])
// // 	{
// // 		if (s[i] == '\'')
// // 			stat = 1;
// // 		if (s[i] == '\"')
// // 			stat = 2;
// // 		i++;
// // 	}
// // 	return (stat);
// // }

// static int	pars_count_word(char const *s)
// {
// 	size_t	count;
// 	size_t	i;

// 	i = 0;
// 	count = 0;
// 	while ((s[i] == 9 || s[i] == 32) && s[i])
// 		i++;
// 	while (s[i])
// 	{
// 		if (s[i] == 9 || s[i] == 32)
// 			count++;
// 		while ((s[i] == 9 || s[i] == 32) && s[i])
// 			i++;
// 		if ((s[i] != 9 && s[i] != 32) && s[i])
// 			i++;
// 	}
// 	if (!s[0])
// 		count = 0;
// 	else if ((s[i - 1] != 9 && s[i - 1] != 32))
// 		count++;
// 	return (count);
// }

// char	**ft_pars_word(char const *s, char **tab, int nb)
// {
// 	int	i;
// 	int	j;
// 	int	l;

// 	i = 0;
// 	j = 0;
// 	while (j < nb)
// 	{
// 		l = 0;
// 		while (s[i] && (s[i] == 9 || s[i] == 32))
// 			i++;
// 		while (s[i] && (!ft_isalpha(s[i])))
// 			l++;
// 		printf("%d\n", l);
// 		tab[j] = (char *)malloc(sizeof(char) * (l + 1));
// 		if (!tab[j])
// 			return (NULL);
// 		ft_strlcpy(tab[j], &s[i], l);
// 		i += l;
// 		j++;
// 	}
// 	return (tab);
// }

// char	**ft_pars(char const *s)//, t_data *d)
// {
// 	int			i;
// 	// int			s;
// 	// int			d;
// 	char	**tab;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	// s = check_in(str, '\'');
// 	// d = check_in(str, '\"');
// 	tab = (char **)malloc(sizeof(char *) * (pars_count_word(s) + 1));
// 	if (!tab)
// 		return (NULL);
// 	tab = ft_pars_word(s, tab, pars_count_word(s));
// 	if (!tab)
// 	{
// 		free(tab);
// 		return (NULL);
// 	}
// 	tab[pars_count_word(s)] = 0;
// 	return (tab);
// }

// int main(int ac, char **av)
// {
// 	int 	i;
// 	char	*str;
// 	char	**tab;
	
// 	(void)ac;
// 	i = 0;
// 	str = av[1];
// 	// printf("%d\n", check_in(av[1], '\"'));
// 	// printf("%d\n", check_in(av[1], '\''));
// 	// printf("%d\n", pars_count_word(av[1]));
// 	tab = ft_pars(str);
// 	if (!tab)
// 		return (0);
// 	while (i < pars_count_word(str))
// 	{
// 		printf("%s   %zu\n", tab[i], ft_strlen(tab[i]));
// 		i++;
// 	}
// 	return (0);
// }
