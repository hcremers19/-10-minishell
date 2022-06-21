/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_eng_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:38:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/13 20:38:18 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	loop_check_env(t_one *cmd)
{
	int	j;

	j = 0;
	while (cmd->pars_tab[j])
	{
		if ((check_c_in(cmd->pars_tab[j], '$') >= 0 \
			&& cmd->pars_tab[j][0] == '\"') \
			|| (check_c_in(cmd->pars_tab[j], '$') >= 0 \
			&& cmd->pars_tab[j][0] != '\''))
		{
			while (check_c_in(cmd->pars_tab[j], '$') >= 0)
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

int	get_level(t_one *cmd, int i)
{
	if (cmd->next == NULL)
		return (0);
	else if (i == 0)
		return (2);
	return (1);
}

int	init_cmds(void)
{
	int		i;
	t_one	*tmp;

	i = 0;
	g_d.all->first->level = 0;
	tmp = g_d.all->first;
	while (g_d.all->first)
	{
		g_d.all->first->pos = g_d.all->nb_cmd - i - 1;
		g_d.all->first->cmd = g_d.all->first->pars_tab[0];
		g_d.all->first->level = get_level(g_d.all->first, i);
		g_d.all->first->infile = 0;
		g_d.all->first->outfile = 1;
		if (check_lst_stat(g_d.all->first))
			return (-19);
		if (loop_check_env(g_d.all->first))
			return (-19);
		g_d.all->first = g_d.all->first->next;
		i++;
	}
	g_d.all->first = tmp;
	return (0);
}
