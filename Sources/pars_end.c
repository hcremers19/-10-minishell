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

char	*join_mat(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len_tab_string(tab) + 1));
	if (!str)
		return (NULL);
	while (tab && tab[i])
	{
		str = ft_strcat(str, tab[i]);
		if (!str)
			return (NULL);
		i++;
	}
	ft_free_tab(tab);
	return (str);
}

char	*env_or_not_env(char *str, t_data *d)
{
	t_list	*tmp;
	char	*ret;

	tmp = d->env_list;
	while (d->env_list && str)
	{
		if (!ft_strncmp(str, d->env_list->name, ft_strlen(str)))
		{
			ret = (char *)malloc(sizeof(char) * (ft_strlen(d->env_list->content) + 1));
			if (!ret)
				return (NULL);
			ret = d->env_list->content;
			// free(str);
			d->env_list = tmp;
			return (ret);
		}
		else
			d->env_list = d->env_list->next;
	}
	d->env_list = tmp;
	return (str);
}

char	*check_env_var(char *str, t_data *d)
{
	int		j;
	int		k;
	int		t;
	char	*ret;
	char	**tmp_tab;

	tmp_tab = (char **)malloc(sizeof(char *) * 4);
	if (!tmp_tab)
		return (NULL);
	t = 0;
	j = check_c_in(str, '$');
	if (j > 0)
	{
		tmp_tab[t] = ft_substr(str, 0, j);
		if (!tmp_tab[t])
			return (NULL);
		printf("===== %d - %s\n", t, tmp_tab[t]);
		t++;
	}
	k = j;
	j++;
	while (str[j] && str[j] != '$' && str[j] != 9 && str[j] != 32 && str[j] != 34)
		j++;
	if (j - k - 1 > 0)
	{
		tmp_tab[t] = ft_substr(str, k + 1, j - k - 1);
		if (!tmp_tab[t])
			return (NULL);
	}
	else
		return (str);
	printf("===== %d - %s\n", t, tmp_tab[t]);
	tmp_tab[t] = env_or_not_env(tmp_tab[t], d);
	if (!tmp_tab[t])
		return (NULL);
	printf("===== %d - %s\n", t, tmp_tab[t]);
	if (j < ft_strlen(str))
	{
		tmp_tab[++t] = ft_substr(str, j, ft_strlen(str) - j + 1);
		if (!tmp_tab[t])
			return (NULL);
		printf("===== %d - %s\n", t, tmp_tab[t]);
	}
	ret = join_mat(tmp_tab);
	if (!ret)
		return (NULL);
	return (ret);
}

int	loop_check_env(t_one *cmd, t_data *d)
{
	int	j;

	j = 0;
	while (cmd->pars_tab[j])
	{
		if ((check_c_in(cmd->pars_tab[j], '$') >= 0
			 && cmd->pars_tab[j][0] == '\"')
			 || (check_c_in(cmd->pars_tab[j], '$') >= 0
			  && cmd->pars_tab[j][0] != '\''))
		{
			cmd->pars_tab[j] = check_env_var(cmd->pars_tab[j], d);
			if (!cmd->pars_tab[j])
				return (-19);
		}
		j++;
	}
	return (0);
}

int	init_cmds(t_data *d)
{
	int	i;
	t_one	*tmp;

	i = 0;
	tmp = d->all->first;
	while (d->all->first)
	{
		d->all->first->pos = d->all->nb_cmd - i - 1;
		if (loop_check_env(d->all->first, d))
			return (-19);
		d->all->first = d->all->first->next;
		i++;
	}
	d->all->first = tmp;
	return (0);
}
