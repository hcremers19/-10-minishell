/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:44:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/17 14:44:18 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_lst_stat(t_one *cmd)
{
	int	i;
	int	pos;

	i = 1;
	while (cmd->pars_tab[i])
	{
		pos = check_c_in(cmd->pars_tab[i], '$') >= 0;
		if (pos >= 0 && cmd->pars_tab[i][pos + 1] == '?')
		{
			cmd->pars_tab[i] = replace_lst_stat(cmd->pars_tab[i], pos);
			if (cmd->pars_tab[i])
				return (-19);
		}
		i++;
	}
	return (0);
}

char	*fill_lst_stat(char *str)
{
	char	*tmp;

	tmp = ft_itoa(d.error_code);
	if (!tmp)
		return (NULL);
	str = (char *)malloc(sizeof(char) * 4);
	if (!str)
		return (NULL);
	ft_strcpy(str, tmp);
	return (str);
}

char	*replace_lst_stat(char *str, int pos)
{
	int		t;
	char	*ret;
	char	**tmp_tab;

	tmp_tab = (char **)malloc(sizeof(char *) * 4);
	if (!tmp_tab)
		return (NULL);
	t = 0;
	if (pos > 0)
	{
		tmp_tab[t] = ft_substr(str, 0, pos + 1);
		if (!tmp_tab[t])
			return (NULL);
		t++;
	}
	tmp_tab[t] = fill_lst_stat(tmp_tab[t]);
	if (!tmp_tab[t])
		return (NULL);
	if (pos + 2 + 1 < ft_strlen(str))
	{
		tmp_tab[++t] = ft_substr(str, pos + 2, ft_strlen(str) - pos + 2);
		if (!tmp_tab[t])
			return (NULL);
	}
	ret = join_mat(tmp_tab);
	if (!ret)
		return (NULL);
	return (ret);
}
