/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:10 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/14 11:13:17 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	**get_path(char *env[])
{
	char	*all_path;
	char	**split_path;
	int		i;

	i = -1;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	if (i == len_tab(env))
		return (NULL);
	all_path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	if (!all_path)
		return (NULL);
	split_path = ft_split(all_path, ':');
	if (!split_path)
	{
		free(all_path);
		return (NULL);
	}
	free(all_path);
	return (split_path);
}

void	close_pipe(int fd[2])
{
	close(fd[1]);
	close(fd[0]);
}

void	ft_free(char **paths, char **cmd)
{
	int	path_len;
	int	cmd_len;

	path_len = len_tab(paths);
	cmd_len = len_tab(cmd);
	while (paths && (path_len >= 0))
		free(paths[path_len--]);
	while (cmd && (cmd_len >= 0))
		free(cmd[cmd_len--]);
	if (paths)
		free(paths);
	if (cmd)
		free(cmd);
}

void	perror_cnf(char *str, char *cmd, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd("\n", fd);
}

void	ft_end_process(char *cmd_p, char **cmd, char **path, t_one *cmd_str)
{
	if (ft_strncmp(cmd_p, cmd[0], ft_strlen(cmd_p)) == 0)
		cmd_p = cmd[0];
	if (!check_builtin(cmd_str))
		execve(cmd_p, cmd, d.env_tab);	 // Quand même présente ?
	if (access(cmd_p, F_OK) != 0 && !check_builtin(cmd_str))
	{
		d.error_code = 127;
		perror_cnf("command not found: ", cmd[0], 2);
	}
	free(cmd_p);
	ft_free(path, cmd);
	exit(d.error_code);
}
