/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/07/05 21:35:43 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	--------------------------------------------------------------------------
**	Reproduce 'pwd' built-in command's behaviour:
**	Display the pathname of the current working directory on stdout
**	-----------------------------------------------------------------------	*/

void	ft_pwd(void)
{
	ft_putstr_fd(getcwd(NULL, 0), 1);
	ft_putchar_fd(10, 1);
	g_d.error_code = 0;
}

/*	--------------------------------------------------------------------------
**	Create a new environment variable and insert it in the 'temporary'
**	environment
**	-----------------------------------------------------------------------	*/

int	tmp_var(char *name, char *content)
{
	t_env	*tmp;

	tmp = ft_env_lststr(g_d.env_list, name);
	if (!tmp)
	{
		tmp = ft_env_lststr(g_d.tmp_list, name);
		if (!tmp)
			ft_env_lstadd_front(&g_d.tmp_list, ft_env_lstnew(name, content));
		else
		{
			tmp->content = ft_strdup(content);
			if (!tmp->content)
				return (-19);
		}
	}
	else
	{
		tmp->content = ft_strdup(content);
		if (!tmp->content)
			return (-19);
	}
	return (0);
}

/*	--------------------------------------------------------------------------
**	Reproduce 'export' built-in command's behaviour:
**	Transfer an environment variable from the 'temporary' environment to the
**	'definitive' environment, and delete it from the temporary list.
**	If a name and its content are found as arguments, immediately insert them
**	in the definitive list.
**	-----------------------------------------------------------------------	*/

int	ft_export(char *name)
{
	t_env	*tmp;
	char	*content;
	char	*dupname;

	tmp = ft_env_lststr(g_d.env_list, name);
	if (!tmp)
	{
		tmp = ft_env_lststr(g_d.tmp_list, name);
		if (tmp)
		{
			content = ft_strdup(tmp->content);
			dupname = ft_strdup(tmp->name);
			if (!content || !dupname)
				return (-19);
			ft_env_lstadd_back(&g_d.env_list, ft_env_lstnew(dupname, content));
			ft_env_lstdelone(tmp, free);
		}
	}
	return (0);
}

/*	--------------------------------------------------------------------------
**	Reproduce 'unset' built-in command's behaviour:
**	Delete an environment variable either from the 'temporary' environment or
**	the 'definitive' one
**	-----------------------------------------------------------------------	*/

void	ft_unset(char *name)
{
	ft_env_lstdelone(ft_env_lststr(g_d.tmp_list, name), free);
	ft_env_lstdelone(ft_env_lststr(g_d.env_list, name), free);
	g_d.error_code = 0;
}

/*	--------------------------------------------------------------------------
**	Reproduce 'env' command's behaviour:
**	Display the list of all 'definitive' environment variables on stdout
**	-----------------------------------------------------------------------	*/

void	ft_env(void)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list)
	{
		if (g_d.env_list->name || g_d.env_list->content)
		{
			ft_putstr_fd(g_d.env_list->name, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(g_d.env_list->content, 1);
			ft_putchar_fd(10, 1);
		}
		g_d.env_list = g_d.env_list->next;
	}
	g_d.env_list = tmp;
	g_d.error_code = 0;
}
