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

static int	get_type(t_one *stru)
{
	int	i;
	int	j;

	i = 0;
	while (stru->pars_tab[i])
	{
		if (stru->pars_tab[i][0] == 39)
			return (3);
		else if (stru->pars_tab[i][0] == 34)
		{
			j = 0;
			while (stru->pars_tab[i][j])
			{
				if (stru->pars_tab[i][j] == 36)
					return (2);
				j++;
			}
			return (1);
		}
		else if (check_c_in(stru->pars_tab[i], '$'))
			return (4);
		i++;
	}
	return (0);
}

// /////////// TRANSFORMER CE QUI SUIT $ EN LA VARIABLE ENV CORRESPONDANTE

// static int	check_env_var(t_one *stru, t_data *d)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		t;
// 	char	**tmp_tab;

// 	i = 0;
// 	while (stru->pars_tab[i])
// 	{
// 		tmp_tab = (char **)malloc(sizeof(char *) * 4);
// 		if (!tmp_tab)
// 			return (-19);
// 		j = check_c_in(stru->pars_tab[i], '$');
// 		if (j && j < ft_strlen(stru->pars_tab[i]))
// 		{
// 			k = j;
// 			while(stru->pars_tab[i][j] || stru->pars_tab[i][j] != '$'
// 				 || stru->pars_tab[i][j] != 9 || stru->pars_tab[i][j] != 32)
// 				j++;
// 			t = 0;
// 			tmp_tab[t] = ft_substr(stru->pars_tab[i], 0, k - 1);
// 			if (!tmp_tab[t])
// 				return (-19);
// 			tmp_tab[++t] = env_or_not_env(stru->pars_tab[i], d);
// 			if (!tmp_tab[t])
// 				return (-19);
// 			tmp_tab[++t] = ft_substr(stru->pars_tab[i], j, ft_strlen(stru->pars_tab[i]));
// 			if (!tmp_tab[t])
// 				return (-19);
// 			free(stru->pars_tab[i]);
// 			stru->pars_tab[i] = join_mat(tmp_tab);
// 			if (!stru->pars_tab[i])
// 				return (-19);
// 		}
// 		else
// 			free(tmp_tab);
// 		i++;
// 	}
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


int	init_cmds(t_data *d, int nb)
{
	int	i;
	t_one	*tmp;

	i = 0;
	tmp = d->all->first;
	while (d->all->first)
	{
		d->all->first->pos = nb - i - 1;
		d->all->first->type = get_type(d->all->first);
		// if (d->all->first->type == 2 || d->all->first->type == 4)
		// {
		// 	if (check_env_var(d->all->first, d))
		// 		return (-19);
		// }
		d->all->first = d->all->first->next;
		i++;
	}
	d->all->first = tmp;
	return (0);
}
