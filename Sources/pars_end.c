/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:38:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/04 19:34:36 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Check if there are $? or $VAR_NAME in ordre to replace
	them by their content. Does loop while $ is present in
	the string.
	---------------------------------------------------------	*/

int	check_dollar(t_one *cmd)
{
	int	i;
	int	pos;

	i = 0;
	while (cmd->pars_tab[i])
	{
		if ((check_c_in(cmd->pars_tab[i], '$') >= 0 \
			&& cmd->pars_tab[i][0] == '\"') \
			|| (check_c_in(cmd->pars_tab[i], '$') >= 0 \
			&& cmd->pars_tab[i][0] != '\''))
		{
			pos = check_c_in(cmd->pars_tab[i], '$');
			if (loop_check_dollar(cmd->pars_tab[i], pos))
				return (-19);
		}
		i++;
	}
	return (0);
}

/////  Checker normage qui q foutu le bordel

int	loop_check_dollar(char *str, int pos)
{
	while (pos >= 0 && str[pos + 1])
	{
		if (str[pos + 1] == '?')
		{
			str = replace_lst_stat(str, pos);
			if (!str)
				return (-19);
		}
		else if (ft_isalpha(str[pos + 1]))
		{
			str = check_env_var(str);
			if (!str)
				return (-19);
		}
		pos = check_c_in(str, '$');
	}
	return (0);
}

/*	---------------------------------------------------------
	Set level of the command. Level is the position of the 
	command in the input. '2' for the first one, '0' for
	the last one and '1' for the ones between them.
	---------------------------------------------------------	*/

int	get_level(t_one *cmd, int i)
{
	if (cmd->next == NULL)
		return (0);
	else if (i == 0)
		return (2);
	return (1);
}

/*	---------------------------------------------------------
	Initiation of struct of command parameters.
	---------------------------------------------------------	*/

void	init_cmds_values(t_one *o_cmd, int i)
{
	o_cmd->pos = g_d.all->nb_cmd - i - 1;
	o_cmd->cmd = o_cmd->pars_tab[0];
	o_cmd->level = get_level(o_cmd, i);
	o_cmd->infile = 0;
	o_cmd->outfile = 1;
}

/*	---------------------------------------------------------
	End the creation and initiation of the command linked
	list. Check for temporary environnement variables, last
	command status or environnement variable.
	---------------------------------------------------------	*/

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
		if (check_dollar(g_d.all->first))
			return (-19);
		i++;
		g_d.all->first = g_d.all->first->next;
	}
	g_d.all->first = tmp;
	return (0);
}
