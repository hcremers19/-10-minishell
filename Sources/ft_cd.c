/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:34:05 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/29 16:59:56 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ch_pwd_env(char *varname, char *wd)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list->name || g_d.env_list->content)
	{
		if (!ft_strncmp(varname, g_d.env_list->name, 6))
		{
			free(g_d.env_list->content);
			g_d.env_list->content
				= (char *)malloc(sizeof(char) * (ft_strlen(wd) + 1));
			if (!g_d.env_list->content)
				return (1);
			g_d.env_list->content = wd;
			g_d.env_list->content[ft_strlen(wd) + 1] = 0;
			g_d.env_list = tmp;
			return (0);
		}
		else
			g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	return (1);
}

// int	ch_pwd_env(void)
// {
// 	t_env	*tmp;

// 	tmp = g_d.env_list;
// 	while (g_d.env_list->name || g_d.env_list->content)
// 	{
// 		if (!ft_strncmp("PWD", g_d.env_list->name, 3))
// 		{
// 			free(g_d.env_list->content);
// 			g_d.env_list->content
// 				= (char *)malloc(sizeof(char)
// 					* (ft_strlen(getcwd(NULL, 0)) + 1));
// 			if (!g_d.env_list->content)
// 				return (1);
// 			g_d.env_list->content = getcwd(NULL, 0);
// 			g_d.env_list->content[ft_strlen(getcwd(NULL, 0)) + 1] = 0;
// 			g_d.env_list = tmp;
// 			return (0);
// 		}
// 		else
// 			g_d.env_list = g_d.env_list->next;
// 	}
// 	g_d.env_list = tmp;
// 	return (1);
// }

int	ft_cd(char *path)
{
	char	*owd;
	char	*tmp;

	owd = getcwd(NULL, 0);
	if (path[0] == '~')
	{
		tmp = ft_strjoin(ft_env_lststr(g_d.env_list, "HOME")->content,
				ft_substr(path, 1, ft_strlen(path)));
		free(path);
		path = tmp;
	}
	if (chdir(path))
	{
		ft_putstr_fd("cd: no such path or directory: ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd(10, 1);
		return (1);
	}
	ch_pwd_env("OLDPWD", owd);
	ch_pwd_env("PWD", getcwd(NULL, 0));
	return (0);
}
