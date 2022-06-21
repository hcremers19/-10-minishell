/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:34:05 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/20 11:04:12 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ch_oldpwd_env(void)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list->name || g_d.env_list->content)
	{
		if (!ft_strncmp("OLDPWD", g_d.env_list->name, 6))
		{
			free(g_d.env_list->content);
			g_d.env_list->content = (char *)malloc(sizeof(char) * (ft_strlen(getcwd(NULL, 0)) + 1));
			if (!g_d.env_list->content)
				return (1);
			g_d.env_list->content = getcwd(NULL, 0);
			g_d.env_list->content[ft_strlen(getcwd(NULL, 0)) + 1] = 0;
			g_d.env_list = tmp;
			return (0);
		}
		else
			g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	return (1);
}

int	ch_pwd_env(void)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list->name || g_d.env_list->content)
	{
		if (!ft_strncmp("PWD", g_d.env_list->name, 3))
		{
			free(g_d.env_list->content);
			g_d.env_list->content = (char *)malloc(sizeof(char) * (ft_strlen(getcwd(NULL, 0)) + 1));
			if (!g_d.env_list->content)
				return (1);
			g_d.env_list->content = getcwd(NULL, 0);
			g_d.env_list->content[ft_strlen(getcwd(NULL, 0)) + 1] = 0;
			g_d.env_list = tmp;
			return (0);
		}
		else
			g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	return (1);
}

int	ft_cd(char *path)
{
	if (ch_oldpwd_env())
		return (1);
	if (chdir(path))
	{
		ft_putstr_fd("Incorrect path : ", 1);
		ft_putstr_fd(path, 1);
		ft_putchar_fd(10, 1);
		return (1);
	}
	if (ch_pwd_env())
		return (1);
	return (0);
}
