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

int pars_len(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && ((s[i + len] != 9 && s[i + len] != 32)
		 || d.all->close_stat != 0))
	{// 9 = tab, 32 = space
		if (d.all->close_stat == 0 && s[i + len] == 39)// 39 = simple guillemet
			d.all->close_stat = 1;
		else if (d.all->close_stat == 0 && s[i + len] == 34)// 34 = double guillemet
			d.all->close_stat = 2;
		else if ((s[i + len] == 39 || s[i + len] == 34) && d.all->close_stat != 0)
			d.all->close_stat = 0;
		if (d.all->close_stat == 0 && (s[i + len] == 60
			 || s[i + len] == 62 || s[i + len] == 124))// 60 = plus petit ; 62 = plus grand ; 124 = pipe
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
		tab[j] = (char *)malloc(sizeof(char) * (l + 1));
		if (!tab[j])
			return (NULL);
		ft_strlcpy(tab[j], &s[i], l);
		i += l;
		j++;
	}
	return (tab);
}
// -----------> 9
char	**ft_pars_line(char const *s)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (pars_count(s) + 1));
	if (!tab)
		return (NULL);
	d.s_free = 11;
	tab = ft_pars_word(s, tab, pars_count(s));
	d.s_free = 13;
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
	t_one	*init_tmp;//??

	i = 0;
	j = 0;
	d.all->init_tab = ft_pars_line(s);
	if (!d.all->init_tab)
		return (NULL);
	d.all->first = (t_one *)malloc(sizeof(t_one));
	if (!d.all->first)
		return (NULL);
	d.s_free = 15;
////////////////////////////////////////////////////////////
	tmp = d.all->first;
	init_tmp = d.all->first;/////// utile ?
	while (tmp) 
	{
		tmp->pars_tab = copy_line_tab(tmp->pars_tab, j);
		if (!tmp->pars_tab)
			return (NULL);
		j += len_tab(tmp->pars_tab) + 1;
		if (j >= len_tab(d.all->init_tab))
			tmp->next = NULL;
		else
		{
			tmp->next = (t_one *)malloc(sizeof(t_one));
			if (!tmp->next)
				return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	d.s_free = 17;
	d.all->nb_cmd = i;
	d.all->first = init_tmp;/////// utile ? 
	if (init_cmds()) // envoit vers le dossier pars_end.c
		return (NULL);
	return (d.all->first);
}
