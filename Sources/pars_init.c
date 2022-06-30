/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:45:57 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/30 15:25:21 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	pars_len(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && ((s[i + len] != 9 && s[i + len] != 32) \
			|| g_d.c_s != 0))
	{
		if (g_d.c_s == 0 && s[i + len] == 39)
			g_d.c_s = 1;
		else if (g_d.c_s == 0 && s[i + len] == 34)
			g_d.c_s = 2;
		else if ((s[i + len] == 39 || s[i + len] == 34) \
			&& g_d.c_s != 0)
			g_d.c_s = 0;
		if (g_d.c_s == 0 && s[i + len] == 124)
		{
			if (s[i + len] == s[i + len + 1] && len == 0)
					len += 2;
			else if (len == 0)
					len++;
			break ;
		}
		len++;
	}
	return (len);
}

int	pars_count(char const *s)
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
		l = pars_len(s, i);
		tab[j] = ft_calloc(l + 1, sizeof(char));
		if (!tab[j])
			return (NULL);
		ft_strlcpy(tab[j], &s[i], l);
		i += l;
		j++;
	}
	return (tab);
}

char	**ft_pars_line(char const *s)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc(pars_count(s) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	g_d.s_free = 9;
	tab = ft_pars_word(s, tab, pars_count(s));
	if (!tab)
		return (NULL);
	tab[pars_count(s)] = NULL;
	g_d.s_free = 11;
	return (tab);
}
