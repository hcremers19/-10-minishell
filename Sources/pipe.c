/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:00 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/07 15:51:16 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static void	i_find_a_signal(int this_signal)
{
	if (this_signal == SIGQUIT)
	{
		ft_putstr_fd("QUIT: 3", 1);
		g_d.error_code_tmp = 131;
		kill(g_d.pid, SIGKILL);
	}
	else
	{
		ft_putstr_fd("^C", 1);
		g_d.error_code_tmp = 130;
	}
	ft_putstr_fd("\n", 1);
}

void	process(t_one *cmd, int to_exec)
{
	char	**paths;
	char	*cmd_path;

	if (ft_strlen(cmd->pars_tab[0]) > 2 && cmd->pars_tab[0][0] == '.'
		&& cmd->pars_tab[0][1] == '/' && to_exec)
		ft_end_process(cmd->pars_tab[0], NULL, cmd);
	paths = get_path();
	if (no_path(paths, cmd, to_exec))
		return ;
	cmd_path = find_cmd_path(paths, cmd);
	if (to_exec)
		ft_end_process(cmd_path, paths, cmd);
	if (paths)
	{
		if (cmd_path)
			free(cmd_path);
		ft_free_tab(paths);
	}
}

void	child_process(t_one *cmd, int next_fd[2], int pre_fd[2])
{
	if (g_d.all->nb_cmd == 1)
	{
		if (dup2(cmd->outfile, 1) < 0 || dup2(cmd->infile, 0) < 0)
			return (perror("fd"));
	}
	else
		multi_pipe(next_fd, pre_fd, cmd);
	if (!check_builtin(cmd))
		process(cmd, 1);
	else
	{
		builtin_cmds(cmd);
		process(cmd, 0);
		exit(0);
	}
}

void	ft_pipe_2(t_one *cmd, int tmp, int next_fd[2])
{
	if ((g_d.error_code_tmp == 130
			|| g_d.error_code_tmp == 131))
		g_d.error_code = g_d.error_code_tmp;
	else
		g_d.error_code = tmp / 255;
	if (cmd->pars_tab[0])
		builtin_cmds_env(cmd);
	if (cmd->next)
		ft_pipe(next_fd, cmd->next);
	else
		process(cmd, 0);
	close_pipe(next_fd);
}

void	ft_pipe(int pre_fd[2], t_one *cmd)
{
	int		next_fd[2];
	int		tmp;
	pid_t	pid;

	g_d.error_code_tmp = 0;
	if (!(!ft_strlen(cmd->pars_tab[0])
			|| ft_strncmp(cmd->pars_tab[0], "exit", 4)))
		ft_exit(cmd);
	if (pipe(next_fd) == -1)
		return (perror("pipe"));
	pid = fork();
	g_d.pid = pid;
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		child_process(cmd, next_fd, pre_fd);
	else
	{
		close_pipe(pre_fd);
		signal(SIGINT, i_find_a_signal);
		signal(SIGQUIT, i_find_a_signal);
		waitpid(pid, &tmp, 0);
		ft_pipe_2(cmd, tmp, next_fd);
	}
}
