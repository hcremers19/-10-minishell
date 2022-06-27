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
			return (NULL);
		t++;
	}
	tmp_tab[t] = ft_itoa(g_d.error_code);
	if (!tmp_tab[t])
		return (NULL);
	if (pos + 2 < ft_strlen(str))
	{
		tmp_tab[++t] = ft_substr(str, pos + 2, ft_strlen(str) - pos + 1);
		if (!tmp_tab[t])
			return (NULL);
	}
	free(str);
	return (join_mat(tmp_tab));
}

int	check_lst_stat(t_one *cmd)
{
	int	i;
	int	pos;

	i = 1;
	while (cmd->pars_tab[i])
	{
		if ((check_c_in(cmd->pars_tab[i], '$') >= 0 \
			&& cmd->pars_tab[i][0] == '\"') \
			|| (check_c_in(cmd->pars_tab[i], '$') >= 0 \
			&& cmd->pars_tab[i][0] != '\''))
		{
			pos = check_c_in(cmd->pars_tab[i], '$');
			if (pos >= 0)
			{
				if (cmd->pars_tab[i][pos + 1] == '?')
				{
					cmd->pars_tab[i] = replace_lst_stat(cmd->pars_tab[i], pos);
					if (!cmd->pars_tab[i])
						return (-19);
				}
			}
		}
		i++;
	}
	return (0);
}
