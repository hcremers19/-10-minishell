/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/11 12:05:27 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// 9 = tab, 32 = space
// 39 = simple guillemet
// 34 = double guillemet
// 60 = plus petit ; 62 = plus grand ; 124 = pipe

int	pars_len(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && ((s[i + len] != 9 && s[i + len] != 32) \
			|| g_d.all->c_s != 0))
	{
		if (g_d.all->c_s == 0 && s[i + len] == 39)
			g_d.all->c_s = 1;
		else if (g_d.all->c_s == 0 && s[i + len] == 34)
			g_d.all->c_s = 2;
		else if ((s[i + len] == 39 || s[i + len] == 34) \
			&& g_d.all->c_s != 0)
			g_d.all->c_s = 0;
		if (g_d.all->c_s == 0 && (s[i + len] == 60 \
			|| s[i + len] == 62 || s[i + len] == 124))
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
	g_d.s_free = 11;
	tab = ft_pars_word(s, tab, pars_count(s));
	g_d.s_free = 13;
	if (!tab)
		return (NULL);
	tab[pars_count(s)] = NULL;
	return (tab);
}

t_one	*ft_pars(char *s)
{
	int		j;
	int		i;
	t_one	*tmp;

	i = 0;
	j = 0;
	g_d.all->init_tab = ft_pars_line(s);
	if (!g_d.all->init_tab)
		return (NULL);
	g_d.all->first = ft_calloc(1, sizeof(t_one));
	if (!g_d.all->first)
		return (NULL);
	g_d.s_free = 15;
////////////////////////////////////////////////////////////
	tmp = g_d.all->first;
	while (tmp)
	{
		tmp->pars_tab = copy_line_tab(tmp->pars_tab, j);
		if (!tmp->pars_tab)
			return (NULL);
		j += len_tab(tmp->pars_tab) + 1;
		if (j >= len_tab(g_d.all->init_tab))
			tmp->next = NULL;
		else
		{
			tmp->next = ft_calloc(1, sizeof(t_one));
			if (!tmp->next)
				return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	g_d.s_free = 17;
	g_d.all->nb_cmd = i;
	if (init_cmds())
		return (NULL);
	return (g_d.all->first);
}
