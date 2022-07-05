/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:22 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 20:25:49 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	no_path(char **paths, t_one *cmd, int to_ex)
{
	if (!paths && to_ex)
	{
		if (access(cmd->pars_tab[0], F_OK) == 0)
		{
			ft_free_tab(paths);
			execve(cmd->pars_tab[0], cmd->pars_tab, g_d.env_tab);
		}
		else if (!check_builtin(cmd))
		{
			perror_cnf("command not found: ", cmd->pars_tab[0], 2);
			g_d.error_code = 127;
			exit (127);
		}
		return (1);
	}
	else if (!paths && !to_ex)
		return (1);
	return (0);
}

char	*find_cmd_path(char **paths, t_one *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_path;

	i = -1;
	while (cmd->pars_tab[0] && paths && paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		if (!cmd_path)
			clean_mat_and_exit(paths);
		if (ft_strncmp(cmd_path, cmd->pars_tab[0], ft_strlen(cmd_path)) == 0)
			break ;
		tmp = ft_strjoin(cmd_path, cmd->pars_tab[0]);
		free(cmd_path);
		if (!tmp)
			clean_mat_and_exit(paths);
		cmd_path = tmp;
		if (!access(cmd_path, F_OK))
			break ;
		if (paths[i + 1])
			free(cmd_path);
	}
	return (cmd_path);
}

void	ft_redirection(int fd_in, int fd_out, int simple, int first)
{
	if (simple == 1 && first == 1)
	{
		close(fd_in);
		if (dup2(fd_out, 1) < 0)
			return (perror("fd"));
		close(fd_out);
	}
	else if (simple == 1 && first == 0)
	{
		close(fd_out);
		if (dup2(fd_in, 0) < 0)
			return (perror("fd"));
		close(fd_in);
	}
	else
	{
		if (dup2(fd_out, 1) < 0 || dup2(fd_in, 0) < 0)
		{
			ft_putnbr_fd(fd_out, 1);
			ft_putnbr_fd(fd_in, 1);
			return (perror("fd"));
		}
		close(fd_out);
		close(fd_in);
	}
}

void	multi_pipe(int next_fd[2], int pre_fd[2], t_one *cmd)
{
	if (cmd->level == 2)
	{
		if (cmd->infile == 0)
			ft_redirection(next_fd[0], next_fd[1], 1, 1);
		else
			ft_redirection(cmd->infile, next_fd[1], 0, 1);
	}
	else if (g_d.all->nb_cmd > 1 && cmd->level != 0)
	{
		close(pre_fd[1]);
		close(next_fd[0]);
		ft_redirection(pre_fd[0], next_fd[1], 0, 0);
	}
	else if (g_d.all->nb_cmd > 1 && cmd->level == 0)
	{
		if (cmd->outfile == 1)
			ft_redirection(pre_fd[0], pre_fd[1], 1, 0);
		else
		{
			close(pre_fd[1]);
			ft_redirection(pre_fd[0], cmd->outfile, 0, 0);
		}
	}
}

void	clean_mat_and_exit(char **paths)
{
	ft_free_tab(paths);
	global_exit();
}
