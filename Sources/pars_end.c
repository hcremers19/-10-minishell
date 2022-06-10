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

int	loop_check_env(t_one *cmd)
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

int	init_cmds(void)
{
	int	i;
	t_one	*tmp;

	i = 0;
	tmp = d.all->first;
	while (d.all->first)
	{
		d.all->first->pos = d.all->nb_cmd - i - 1;
		if (loop_check_env(d.all->first))
			return (-19);
		d.all->first = d.all->first->next;
		i++;
	}
	d.all->first = tmp;
	return (0);
}
