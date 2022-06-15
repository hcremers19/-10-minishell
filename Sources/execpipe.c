/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:59:47 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/15 16:14:52 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int execpipe(void)
{
	int	i;
	int	fd[2];

	i = 0;
	fd[0] = 6;
	fd[1] = 6;
	pipe_rec(d.all, d.env_tab, fd, d.all->first);
	return (0);
}

int builtin_cmds_env(t_one *cmd)
{
	if (!ft_strncmp("export", cmd->cmd, 6))
		ft_export(cmd->pars_tab[1]);
	else if (!ft_strncmp("cd", cmd->cmd, 2))
		ft_cd(cmd->pars_tab[1]);
	else if (!ft_strncmp("unset", cmd->cmd, 5))
		ft_unset(cmd->pars_tab[1]);
	else
		return (1);
	return (0);
}

int builtin_cmds(t_one *cmd)
{
	if (!ft_strncmp("env", cmd->cmd, 3))
		ft_env();
	// else if (!ft_strncmp("exit", cmd->cmd, 4))
	// 	ft_exit();
	else if (!ft_strncmp("pwd", cmd->cmd, 3))
		ft_pwd();
	// else if (!ft_strncmp("echo", cmd->cmd, 4))
	// 	ft_echo();
	else 
		return (1);
	return (0);
}

int check_builtin(t_one *cmd)
{
	return (!ft_strncmp("export", cmd->cmd, 6))
		|| (!ft_strncmp("cd", cmd->cmd, 2))
		|| (!ft_strncmp("unset", cmd->cmd, 5))
		|| (!ft_strncmp("exit", cmd->cmd, 4))
		|| (!ft_strncmp("pwd", cmd->cmd, 3))
		|| (!ft_strncmp("env", cmd->cmd, 3))
		|| (!ft_strncmp("echo", cmd->cmd, 4));
}
