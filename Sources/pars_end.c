/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:38:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/13 20:38:18 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// int	get_type(t_one *stru)
// {
// 	int	i;

// 	i = 0;
// 	while (stru->pars_tab[i])
// 	{
// 		if (stru->pars_tab[i][0] == 39)
// 			return (3);
// 		else if (stru->pars_tab[i][0] == 34)
// 		{
// 			if (check_c_in(stru->pars_tab[i], '$'))
// 				return (2);
// 			return (1);
// 		}
// 		else if (check_c_in(stru->pars_tab[i], '$'))
// 			return (4);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_env_var(char *str, t_data *d)
// {
// 	int		j;
// 	int		k;
// 	int		t;
// 	char	**tmp_tab;

// 	tmp_tab = (char **)malloc(sizeof(char *) * 4);
// 	if (!tmp_tab)
// 		return (-19);
// 	j = check_c_in(str, '$');
// 	if (j)
// 	{
// 		k = j;
// 		while (str[j] || str[j] != '$' || str[j] != 9 || str[j] != 32)
// 			j++;
// 		t = 0;
// 		tmp_tab[t] = ft_substr(str, 0, k - 1);
// 		if (!tmp_tab[t])
// 			return (-19);
// 		tmp_tab[++t] = env_or_not_env(str, d);
// 		if (!tmp_tab[t])
// 			return (-19);
// 		tmp_tab[++t] = ft_substr(str, j, ft_strlen(str));
// 		if (!tmp_tab[t])
// 			return (-19);
// 		str = join_mat(tmp_tab);
// 		if (!str)
// 			return (-19);
// 	}
// 	free(tmp_tab);
// 	return (0);
// }

// char	*env_or_not_env(char *str, t_data *d)
// {
// 	t_list	*res;
// 	char	*ret;

// 	res = ft_lststr(d->env_list, str);
// 	if (res)
// 	{
// 		ret = (char *)malloc(sizeof(char) * (ft_strlen(res->content + 1)));
// 		if (!ret)
// 			return (NULL);
// 		ft_strlcpy(ret, res->content, ft_strlen(res->content));
// 		return (ret);
// 	}
// 	return (NULL);
// }

// char	*join_mat(char **tab)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	while (tab && tab[i])
// 	{
// 		str = ft_strjoin(str, tab[i]);
// 		if (!str)
// 			return (NULL);
// 		free(tab[i]);
// 		i++;
// 	}
// 	return (str);
// }

// int	init_cmds(t_data *d, int nb)
// {
// 	int	i;
// 	int	j;
// 	t_one	*tmp;

// 	i = 0;
// 	tmp = d->all->first;
// 	while (d->all->first)
// 	{
// 		d->all->first->pos = nb - i - 1;
// 		j = 0;
// 		while (d->all->first->pars_tab[j])
// 		{
// 			if ((check_c_in(d->all->first->pars_tab[j], '$') && d->all->first->pars_tab[j][0] == '\"')
// 				 || (check_c_in(d->all->first->pars_tab[j], '$') && d->all->first->pars_tab[j][0] != '\''))
// 			{
// 				if (check_env_var(d->all->first->pars_tab[j], d))
// 					return (-19);
// 			}
// 			j++;
// 		}
// 		d->all->first = d->all->first->next;
// 		i++;
// 	}
// 	d->all->first = tmp;
// 	return (0);
// }
