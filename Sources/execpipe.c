/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:59:47 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 15:46:14 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	--------------------------------------------------------------------------
**	Launching pipe.
**	-----------------------------------------------------------------------	*/

int	execpipe(void)
{
	int	fd[2];

	fd[0] = 6;
	fd[1] = 6;
	ft_pipe(fd, g_d.all->first);
	return (0);
}

/*	--------------------------------------------------------------------------
**	First wave of checks in order to execute the function that matches the
**	received command
**	ft_export, ft_cd, ft_exit an ft_echo are called here if the conditions are
**	OK
**	-----------------------------------------------------------------------	*/

int	builtin_cmds_env(t_one *cmd)
{
	int	i;

	if (!ft_strlcmp("export", cmd->cmd))
	{
		i = 1;
		if (!cmd->pars_tab[i])
			ft_env();
		while (cmd->pars_tab[i])
			if (ft_export(cmd->pars_tab[i++]))
				return (1);
	}
	else if (!ft_strlcmp("cd", cmd->cmd))
	{
		if (cmd->pars_tab[1])
			ft_cd(cmd->pars_tab[1]);
		else
			ft_cd(ft_env_lststr(g_d.env_list, "HOME")->content);
	}
	else if (!ft_strlcmp("unset", cmd->cmd))
		return (ft_unset_launcher(cmd));
	else
		return (1);
	return (0);
}

int	builtin_cmds(t_one *cmd)
{
	if (!ft_strlcmp("env", cmd->cmd))
	{
		if (ft_env_launcher(cmd))
			return (1);
	}
	else if (!ft_strlcmp("pwd", cmd->cmd))
	{
		if (ft_pwd_launcher(cmd))
			return (1);
	}
	else if (!ft_strlcmp("echo", cmd->cmd))
	{
		if (cmd->pars_tab[1])
			ft_echo(cmd->pars_tab);
		else
			ft_putstr_fd("\n", 1);
	}
	else
		return (1);
	return (0);
}

/*	--------------------------------------------------------------------------
**	Checks whether the received command matches one of our homemade functions
**	or not.
**	-----------------------------------------------------------------------	*/	

int	check_builtin(t_one *cmd)
{
	return ((!ft_strlcmp("export", cmd->cmd))
		|| (!ft_strlcmp("cd", cmd->cmd))
		|| (!ft_strlcmp("unset", cmd->cmd))
		|| (!ft_strlcmp("exit", cmd->cmd))
		|| (!ft_strlcmp("pwd", cmd->cmd))
		|| (!ft_strlcmp("env", cmd->cmd))
		|| (!ft_strlcmp("echo", cmd->cmd)));
}
