/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:24:02 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/30 17:42:53 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
		if (access(path, F_OK))
			i++;
		else
		{
			ft_env();
			return (0);
		}
	}
	perror_cnf("command not found: ", cmd->cmd, 2);
	g_d.error_code = 1;
	return (1);
}

int	ft_env_launcher(t_one *cmd)
{
	g_d.error_code = 1;
	if (cmd->pars_tab[1])
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		return (1);
	}
	if (check_ft_env(cmd))
		return (1);
	return (0);
}

int	ft_unset_launcher(t_one *cmd)
{
	if (!cmd->pars_tab[1])
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		g_d.error_code = 1;
		return (1);
	}
	ft_unset(cmd->pars_tab[1]);
	return (0);
}

int	ft_pwd_launcher(t_one *cmd)
{
	if (cmd->pars_tab[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		g_d.error_code = 1;
		return (1);
	}
	ft_pwd();
	return (0);
}
