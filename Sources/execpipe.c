/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:59:47 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/30 12:46:13 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	execpipe(void)
{
	int	i;
	int	fd[2];

	i = 0;
	fd[0] = 6;
	fd[1] = 6;
	ft_pipe(fd, g_d.all->first);
	return (0);
}

int	check_ft_env(t_one *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	paths = get_path();
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i], "/env");
		// ft_putstr_fd(path, 1);
		// ft_putchar_fd(10, 1);
		if (access(path, F_OK))
			i++;
		else
		{
			ft_env();
			return (0);
		}
	}
	perror_cnf("command not found: ", cmd->cmd, 2);
	return (1);
}

int	builtin_cmds_env(t_one *cmd)
{
	if (!ft_strlcmp("export", cmd->cmd))
	{
		if (cmd->pars_tab[1])
			ft_export(cmd->pars_tab[1]);
		else
			ft_env();
	}
	else if (!ft_strlcmp("cd", cmd->cmd))
	{
		if (cmd->pars_tab[1])
			ft_cd(cmd->pars_tab[1]);
		else
			ft_cd(ft_env_lststr(g_d.env_list, "HOME")->content);
	}
	else if (!ft_strlcmp("unset", cmd->cmd))
	{
		if (cmd->pars_tab[1])
			ft_unset(cmd->pars_tab[1]);
		else
		{
			ft_putstr_fd("unset: not enough arguments\n", 2);
			return (1);
		}
	}
	else
		return (1);
	return (0);
}

int	builtin_cmds(t_one *cmd)
{
	if (!ft_strlcmp("env", cmd->cmd))
	{	
		if (check_ft_env(cmd))
			return (1);
	}
	else if (!ft_strlcmp("exit", cmd->cmd))
		ft_exit(cmd);
	else if (!ft_strlcmp("pwd", cmd->cmd))
		ft_pwd();
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
