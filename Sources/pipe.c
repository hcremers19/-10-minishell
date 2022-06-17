/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:00 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/14 11:13:14 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	process(char *envp[], char **all_cmd, t_one *cmd, int to_exec)
{
	char	**paths;
	char	*cmd_path;

	if (ft_strlen(cmd->pars_tab[0]) > 2 && cmd->pars_tab[0][0] == '.'
		&& cmd->pars_tab[0][1] == '/' && to_exec)
		ft_end_process(cmd->pars_tab[0], cmd->pars_tab, NULL, cmd);
	paths = get_path(envp);
	if (no_path(paths, all_cmd, cmd, to_exec))
		return ;
	cmd_path = find_cmd_path(paths, cmd, all_cmd);
	if (to_exec)
		ft_end_process(cmd_path, all_cmd, paths, cmd);
	if (paths)
		ft_free_tab(paths);
}

static void	i_find_a_signal(int this_signal) // ???
{
	if (this_signal == SIGQUIT)
	{
		ft_putstr_fd("^\\QUIT: 3", 1);
		d.error_code_tmp = 131;
		kill(d.pid, SIGKILL);
	}
	else
	{
		ft_putstr_fd("^C", 1);
		d.error_code_tmp = 130;
	}
	ft_putstr_fd("\n", 1);
}

void	child_process(t_all *all, t_one *cmd, int next_fd[2], int pre_fd[2])
{
	if (all->nb_cmd == 1)
	{
		if (dup2(cmd->outfile, 1) < 0 || dup2(cmd->infile, 0) < 0)
			return (perror("fd"));
	}
	else
		multi_pipe(all, next_fd, pre_fd, cmd);
	if (!check_builtin(cmd))
		process(d.env_tab, cmd->pars_tab, cmd, 1);
	else
	{
		builtin_cmds(cmd);
		process(d.env_tab, cmd->pars_tab, cmd, 0);
		exit(0);
	}
}

void	pipe_rec_2(t_all *all, t_one *cmd, int tmp, int next_fd[2])
{
	if ((d.error_code_tmp == 130
			|| d.error_code_tmp == 131))
		d.error_code = d.error_code_tmp;
	else
		d.error_code = tmp / 255;
	if (cmd->pars_tab[0])
		builtin_cmds_env(cmd);
	if (cmd->next)
		pipe_rec(all, d.env_tab, next_fd, cmd->next);
	else
		process(d.env_tab, cmd->pars_tab, cmd, 0);
	close_pipe(next_fd);
}

void	pipe_rec(t_all *all, char **envp, int pre_fd[2], t_one *cmd)
{
	int		next_fd[2];
	int		tmp;
	pid_t	pid;

	(void)envp;
	d.error_code_tmp = 0;
	if (!(!ft_strlen(cmd->pars_tab[0]) || ft_strncmp(cmd->pars_tab[0], "exit", 4)))
		exit(1);///////////// fonction ft_exit here
	if (pipe(next_fd) == -1)
		return (perror("pipe"));
	pid = fork();
	d.pid = pid;
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		child_process(all, cmd, next_fd, pre_fd);
	else
	{
		close_pipe(pre_fd);
		signal(SIGINT, i_find_a_signal);
		signal(SIGQUIT, i_find_a_signal);
		waitpid(pid, &tmp, 0);				// ?
		pipe_rec_2(all, cmd, tmp, next_fd);
	}
}

// Demander à Lisa un tour du propriétaire
// Ne pas copier ce comportement parce que c'est une récursive (voir lignes 108 et 78) et qu'on pourrait faire moins compliqué

