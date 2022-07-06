/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:31:13 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 17:11:34 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	*********************************************************	*/
/*							$ENV_VARIABLE						*/
/*	*********************************************************	*/

/*	---------------------------------------------------------
	Check if the $VAR_NAME in the input string is part of the
	environnement list, the temporary environnement list or not.
	---------------------------------------------------------	*/

int	env_or_not_env(char *str, t_env *list)
{
	t_env	*tmp;

	if (!str)
		return (0);
	tmp = list;
	while (list && str)
	{
		if (!ft_strncmp(str, list->name, ft_strlen(str)) \
			&& ft_strlen(str) == ft_strlen(list->name))
		{
			list = tmp;
			return (-19);
		}
		else
			list = list->next;
	}
	list = tmp;
	return (0);
}

/*	---------------------------------------------------------
	If de the $VAR_NAME exists, it replaces $VAR_NAME by the
	content of it.
	---------------------------------------------------------	*/

char	*replace_env_var(char *str, t_env *list)
{
	t_env	*tmp;
	char	*ret;

	tmp = list;
	ret = NULL;
	while (list)
	{
		if (!ft_strncmp(str, list->name, ft_strlen(str)))
		{
			if (ret)
				free(ret);
			ret = ft_calloc(ft_strlen(list->content) + 1, sizeof(char));
			if (!ret)
				return (NULL);
			ft_strcpy(ret, list->content);
			break ;
		}
		else
			list = list->next;
	}
	list = tmp;
	return (ret);
}

/*	---------------------------------------------------------
	Check_env_var & check_env_var_bis cut the string in three (or less there
	is nothing before and/or after the $VAR_NAME) in order to replace it 
	(if it exists) by its content.
	---------------------------------------------------------	*/

char	*check_env_var_bis(char *str, char **tmp_tab, char *tmp, int t)
{
	int	j;

	j = loop_while(str, g_d.pos);
	if (env_or_not_env(tmp, g_d.env_list))
	{
		tmp_tab[t] = replace_env_var(tmp, g_d.env_list);
		if (!tmp_tab[t++])
			return (ft_free_fct_tab(tmp_tab, tmp));
	}
	else if (env_or_not_env(tmp, g_d.tmp_list))
	{
		tmp_tab[t] = replace_env_var(tmp, g_d.tmp_list);
		if (!tmp_tab[t++])
			return (ft_free_fct_tab(tmp_tab, tmp));
	}
	if (j < ft_strlen(str))
	{
		tmp_tab[t] = ft_substr(str, j, ft_strlen(str) - j + 1);
		if (!tmp_tab[t])
			return (ft_free_fct_tab(tmp_tab, tmp));
	}
	free(tmp);
	tmp_tab[3] = NULL;
	return (join_mat(tmp_tab));
}

char	*check_env_var(char *str)
{
	int		j;
	int		k;
	int		t;
	char	*tmp;
	char	**tmp_tab;

	tmp_tab = ft_calloc(3, sizeof(char *));
	if (!tmp_tab)
		return (NULL);
	t = 0;
	j = g_d.pos;
	if (j > 0)
	{
		tmp_tab[t] = ft_substr(str, 0, j);
		if (!tmp_tab[t++])
			return (ft_free_fct_tab(tmp_tab, NULL));
	}
	k = j;
	j = loop_while(str, j);
	tmp = ft_substr(str, k + 1, j - k - 1);
	if (!tmp)
		return (ft_free_fct_tab(tmp_tab, NULL));
	return (check_env_var_bis(str, tmp_tab, tmp, t));
}

/*	*********************************************************	*/
/*							$?									*/
/*	*********************************************************	*/

/*	---------------------------------------------------------
	Replace '$?' by last command status by cutting the string
	in three if it is needed.
	---------------------------------------------------------	*/	

char	*replace_lst_stat(char *str, int pos)
{
	int		t;
	char	**tmp_tab;

	tmp_tab = ft_calloc(4, sizeof(char *));
	if (!tmp_tab)
		return (NULL);
	t = 0;
	if (pos > 0)
	{
		tmp_tab[t] = ft_substr(str, 0, pos);
		if (!tmp_tab[t])
			return (ft_free_fct_tab(tmp_tab, NULL));
		t++;
	}
	tmp_tab[t] = ft_itoa(g_d.error_code);
	if (!tmp_tab[t])
		return (ft_free_fct_tab(tmp_tab, NULL));
	if (pos + 2 < ft_strlen(str))
	{
		tmp_tab[++t] = ft_substr(str, pos + 2, ft_strlen(str) - pos + 1);
		if (!tmp_tab[t])
			return (ft_free_fct_tab(tmp_tab, NULL));
	}
	return (join_mat(tmp_tab));
}
