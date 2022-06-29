/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_env_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:31:13 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/28 11:58:48 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	env_or_not_env(char *str)
{
	t_env	*tmp;

	if (!str)
		return (0);
	tmp = g_d.env_list;
	while (g_d.env_list && str)
	{
		if (!ft_strncmp(str, g_d.env_list->name, ft_strlen(str)))
		{
			g_d.env_list = tmp;
			return (19);
		}
		else
			g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	return (0);
}

char	*replace_env_var(char *str)
{
	t_env	*tmp;
	char	*ret;

	tmp = g_d.env_list;
	ret = NULL;
	while (g_d.env_list)
	{
		if (!ft_strncmp(str, g_d.env_list->name, ft_strlen(str)))
		{
			ret = ft_calloc(ft_strlen(g_d.env_list->content) + 1, sizeof(char));
			if (!ret)
				return (NULL);
			ft_strcpy(ret, g_d.env_list->content);
			free(str);
			break ;
		}
		else
			g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	return (ret);
}

// char	*check_env_var_1(char *str)
// {
// 	int	
// }

char	*check_env_var(char *str)
{
	int		j;
	int		k;
	int		t;
	char	*tmp;
	char	**tmp_tab;

	tmp_tab = ft_calloc(4, sizeof(char *));
	if (!tmp_tab)
		return (NULL);
	t = 0;
	j = check_c_in(str, '$');
	if (j > 0)
	{
		tmp_tab[t] = ft_substr(str, 0, j);
		if (!tmp_tab[t++])
			return (NULL);
	}
	k = j;
	j = loop_while(str, j);
	tmp = ft_substr(str, k + 1, j - k - 1);
	if (!tmp)
		return (NULL);
	if (env_or_not_env(tmp))
	{
		tmp_tab[t] = replace_env_var(tmp);
		if (!tmp_tab[t++])
			return (NULL);
	}
	if (j < ft_strlen(str))
	{
		tmp_tab[t] = ft_substr(str, j, ft_strlen(str) - j + 1);
		if (!tmp_tab[t])
			return (NULL);
	}
	return (join_mat(tmp_tab));
}

int	loop_check_env(t_one *cmd)
{
	int	j;
	int	pos;

	j = 0;
	while (cmd->pars_tab[j])
	{
		if ((check_c_in(cmd->pars_tab[j], '$') >= 0 \
			&& cmd->pars_tab[j][0] == '\"') \
			|| (check_c_in(cmd->pars_tab[j], '$') >= 0 \
			&& cmd->pars_tab[j][0] != '\''))
		{
			pos = check_c_in(cmd->pars_tab[j], '$');
			while (check_c_in(cmd->pars_tab[j], '$') >= 0 && \
				ft_isalpha(cmd->pars_tab[j][pos + 1]))
			{
				cmd->pars_tab[j] = check_env_var(cmd->pars_tab[j]);
				if (!cmd->pars_tab[j])
					return (-19);
			}
		}
		j++;
	}
	return (0);
}
