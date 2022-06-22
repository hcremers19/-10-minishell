/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/20 12:09:47 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_unset(char *name)
{
	ft_env_lstdelone(ft_env_lststr(g_d.env_list, name), free);
	ft_env_lstfreenull(g_d.env_list);
}// Normalement pas de gestion d'erreur parce que la fonction ne devrait juste rien faire si elle ne trouve pas ce qu'elle cherche

void	ft_export(char *name)
{
	t_env	*tmp; // À tester 🤔

	tmp = ft_env_lststr(g_d.env_list, name);
	if (tmp)
	{
		free(tmp->content);
		tmp->content = ft_strdup(ft_env_lststr(g_d.tmp_list, name)->content);
	}
	ft_env_lstadd_back(&g_d.env_list, ft_env_lststr(g_d.tmp_list, name));
	ft_env_lstdelone(ft_env_lststr(g_d.tmp_list, name), free);
	ft_env_lstfreenull(g_d.tmp_list);
}	// Normalement pas de gestion d'erreur parce que la fonction ne devrait juste rien faire si elle ne trouve pas ce qu'elle cherche

void	tmp_var(char *name, char *content)
{
	ft_env_lstadd_front(&g_d.tmp_list, ft_env_lstnew(name, content));
}

void	ft_env(void)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	while (g_d.env_list->next)
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
	ft_putstr_fd(g_d.env_list->name, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(g_d.env_list->content, 1);
	ft_putchar_fd(10, 1);
	g_d.env_list = tmp;
}

void	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
}	// Aller voir le pwd d'Hugo si ça vaut la peine d'en faire un plus complexe

