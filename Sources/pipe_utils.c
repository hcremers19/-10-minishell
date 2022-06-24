/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:10 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/24 12:03:05 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	**get_path(void)
{
	char	*all_path;
	char	**split_path;

	all_path = ft_env_lststr(g_d.env_list, "PATH")->content;
	if (!all_path)
		return (NULL);
	split_path = ft_split(all_path, ':');
	if (!split_path)
		return (NULL);
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
		execve(cmd_p, cmd,g_d.env_tab);
	if (access(cmd_p, F_OK) != 0 && !check_builtin(cmd_str))
	{
		g_d.error_code = 127;
		perror_cnf("command not found: ", cmd[0], 1);
	}
	free(cmd_p);
	free(path);
	exit(g_d.error_code);
}
