/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:34:05 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/14 15:42:54 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ch_oldpwd_env(void)
{
	t_env	*tmp;

	tmp = d.env_list;
	while (d.env_list->name && d.env_list->content)
	{
		if (!ft_strncmp("OLDPWD", d.env_list->name, 6))
		{
			free(d.env_list->content);
			d.env_list->content = (char *)malloc(sizeof(char) * (ft_strlen(getcwd(NULL, 0)) + 1));
			if (!d.env_list->content)
				return (1);
			d.env_list->content = getcwd(NULL, 0);
			d.env_list->content[ft_strlen(getcwd(NULL, 0)) + 1] = 0;
			d.env_list = tmp;
			return (0);
		}
		else
			d.env_list = d.env_list->next;
	}
	d.env_list = tmp;
	return (1);
}

int	ch_pwd_env(void)
{
	t_env	*tmp;

	tmp = d.env_list;
	while (d.env_list->name && d.env_list->content)
	{
		if (!ft_strncmp("PWD", d.env_list->name, 3))
		{
			free(d.env_list->content);
			d.env_list->content = (char *)malloc(sizeof(char) * (ft_strlen(getcwd(NULL, 0)) + 1));
			if (!d.env_list->content)
				return (1);
			d.env_list->content = getcwd(NULL, 0);
			d.env_list->content[ft_strlen(getcwd(NULL, 0)) + 1] = 0;
			d.env_list = tmp;
			return (0);
		}
		else
			d.env_list = d.env_list->next;
	}
	d.env_list = tmp;
	return (1);
}

int	ft_cd(char *path)
{
	if (ch_oldpwd_env())
		return (1);
	if (chdir(path[1]))
		return (1);
	if (ch_pwd_env())
		return (1);
	return (0);
}
