/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:59:47 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/29 17:32:42 by hcremers         ###   ########.fr       */
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
	if (!ft_strncmp("export", cmd->cmd, 6))
		ft_export(cmd->pars_tab[1]);
	else if (!ft_strncmp("cd", cmd->cmd, 2))
	{
		if (cmd->pars_tab[1])
			ft_cd(cmd->pars_tab[1]);
		else
			ft_cd(ft_env_lststr(g_d.env_list, "HOME")->content);
	}
	else if (!ft_strncmp("unset", cmd->cmd, 5))
		ft_unset(cmd->pars_tab[1]);
	else
		return (1);
	return (0);
}

int	builtin_cmds(t_one *cmd)
{
	if (!ft_strncmp("env", cmd->cmd, 3))
	{	
		if (check_ft_env(cmd))
			return (1);
	}
	else if (!ft_strncmp("exit", cmd->cmd, 4))
		ft_exit(cmd);
	else if (!ft_strncmp("pwd", cmd->cmd, 3))
		ft_pwd();
	else if (!ft_strncmp("echo", cmd->cmd, 4))
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
	return ((!ft_strncmp("export", cmd->cmd, 6))
		|| (!ft_strncmp("cd", cmd->cmd, 2))
		|| (!ft_strncmp("unset", cmd->cmd, 5))
		|| (!ft_strncmp("exit", cmd->cmd, 4))
		|| (!ft_strncmp("pwd", cmd->cmd, 3))
		|| (!ft_strncmp("env", cmd->cmd, 3))
		|| (!ft_strncmp("echo", cmd->cmd, 4)));
}
