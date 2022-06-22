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

int	get_level(t_one *cmd, int i)
{
	if (cmd->next == NULL)
		return (0);
	else if (i == 0)
		return (2);
	return (1);
}

void	init_cmds_values(t_one *o_cmd, int i)
{
	o_cmd->pos = g_d.all->nb_cmd - i - 1;
	o_cmd->cmd = o_cmd->pars_tab[0];
	o_cmd->level = get_level(o_cmd, i);
	o_cmd->infile = 0;
	o_cmd->outfile = 1;
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
		init_cmds_values(g_d.all->first, i);
		if (check_tmp_env(g_d.all->first))
			return (-19);
		if (check_lst_stat(g_d.all->first))
			return (-19);
		if (loop_check_env(g_d.all->first))
			return (-19);
		i++;
		g_d.all->first = g_d.all->first->next;
	}
	g_d.all->first = tmp;
	return (0);
}
