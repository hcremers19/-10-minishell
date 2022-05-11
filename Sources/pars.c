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

int pars_len(char const *s, int i)
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
				if (len == 0)
					len += 2;
			}
			else
			{
				if (len == 0)
					len ++;
			}
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

char	**ft_pars_line(char const *s)
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

t_one	*ft_pars(char const *s, t_data *d)
{
	int		i;
	int		j;
	t_one	*tmp;

	i = 0;
	j = 0;
	d->all->frst_tab = ft_pars_line(s);
	if (!d->all->frst_tab)
		return (NULL);
	d->all->first = (t_one *)malloc(sizeof(t_one));
	if (!d->all->first)
		return (NULL);
	tmp = d->all->first;
	while (tmp)
	{
		tmp->all_cmd = copy_line_tab(tmp->all_cmd, d, int j);
		if (!tmp->all_cmd)
			return (NULL);
		j += len_tab(tmp->all_cmd) + 1;
		if (i == len_tab(d->all->frst_tab))
			tmp->next = NULL;
		else
		{
			tmp = (t_one *)malloc(sizeof(t_one));
			if (!tmp)
				return (NULL);
			init_cmd(tmp, d, i);
		}
		tmp = tmp->next;
		i++;
	}
	if (i != len_tab(d->all->frst_tab))
		return (NULL);
	return (d->all->first);
}

// int main(int ac, char **av)
// {
// 	int 	i;
// 	char	*str;
// 	char	**tab;
	
// 	(void)ac;
// 	i = 0;
// 	str = av[1];
// 	tab = ft_pars_line(str);
// 	if (!tab)
// 		return (0);
// 	while (tab[i])
// 	{
// 		printf("[%d] %zu = %s\n", i, ft_strlen(tab[i]),tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
