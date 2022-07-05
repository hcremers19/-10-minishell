/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:34:05 by hcremers          #+#    #+#             */
/*   Updated: 2022/07/05 19:44:13 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	--------------------------------------------------------------------------
**	Change the content of the 'PWD' or 'OLDPWD' environment variable
**	-----------------------------------------------------------------------	*/

int	ch_pwd_env(char *varname, char *wd)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list->name || g_d.env_list->content)
	{
		if (!ft_strlcmp(varname, g_d.env_list->name))
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

/*	--------------------------------------------------------------------------
**	Reproduce 'cd' built-in command's behaviour:
**	Change the current working directory
**	-----------------------------------------------------------------------	*/

int	ft_cd(char *path)
{
	char	*owd;
	char	*tmp;

	owd = getcwd(NULL, 0);
	if (path[0] == '~')
	{
		tmp = ft_strjoin(ft_env_lststr(g_d.env_list, "HOME")->content,
				ft_substr(path, 1, ft_strlen(path)));
		if (!tmp)
			return (-19);
		free(path);
		path = tmp;
	}
	if (chdir(path))
	{
		ft_putstr_fd("cd: no such path or directory: ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd(10, 1);
		g_d.error_code = 1;
		return (1);
	}
	ch_pwd_env("OLDPWD", owd);
	ch_pwd_env("PWD", getcwd(NULL, 0));
	g_d.error_code = 0;
	return (0);
}
