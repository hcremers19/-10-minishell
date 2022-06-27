/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/27 16:30:01 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// /* debug */

// void	ft_tmp(void)
// {
// 	t_env	*tmp;

// 	tmp = g_d.tmp_list;
// 	while (g_d.tmp_list->next)
// 	{
// 		if (g_d.tmp_list->name || g_d.tmp_list->content)
// 		{
// 			ft_putstr_fd(g_d.tmp_list->name, 1);
// 			ft_putchar_fd('=', 1);
// 			ft_putstr_fd(g_d.tmp_list->content, 1);
// 			ft_putchar_fd(10, 1);
// 		}
// 		g_d.tmp_list = g_d.tmp_list->next;
// 	}
// 	ft_putstr_fd(g_d.tmp_list->name, 1);
// 	ft_putchar_fd('=', 1);
// 	ft_putstr_fd(g_d.tmp_list->content, 1);
// 	ft_putchar_fd(10, 1);
// 	g_d.tmp_list = tmp;
// }

// /* end of debug */

void	ft_unset(char *name)
{
	ft_env_lstdelone(ft_env_lststr(g_d.env_list, name), free);
	// ft_env_lstfreenull(g_d.env_list);
}

// void	ft_export(char *name)
// {
// 	t_env	*tmp; // À tester 🤔
	
// 	ft_putstr_fd("Export variable ", 1); ft_putstr_fd(name, 1); ft_putchar_fd(10, 1);
// 	tmp = ft_env_lststr(g_d.env_list, name);
// 	if (tmp)
// 	{
// 		free(tmp->content);
// 		tmp->content = ft_strdup(ft_env_lststr(g_d.tmp_list, name)->content);
// 	}
// 	ft_env_lstadd_back(&g_d.env_list, ft_env_lststr(g_d.tmp_list, name));
// 	ft_env_lstdelone(ft_env_lststr(g_d.tmp_list, name), free);
// 	ft_putstr_fd("End of export ", 1); ft_putchar_fd(10, 1);
// 	// ft_env_lstfreenull(g_d.tmp_list);
// }	// Normalement pas de gestion d'erreur parce que la fonction ne devrait juste rien faire si elle ne trouve pas ce qu'elle cherche

// void	tmp_var(char *name, char *content)
// {
// 	t_env	*tmp;

// 	tmp = ft_env_lststr(g_d.env_list, name);
// 	if (!tmp)
// {		write(1, "if\n", 3); ft_env_lstadd_front(&g_d.tmp_list, ft_env_lstnew(name, content));
// }	else
// {		ft_export(name); write(1, "else\n", 5);
// 		ft_putstr_fd("TmpVar : ", 1); ft_putstr_fd(tmp->name, 1); ft_putchar_fd(10, 1);
// }}

void	ft_export(char *name)
{
	t_env	*tmp;

	tmp = ft_env_lststr(g_d.env_list, name);
	if (!tmp)
	{
		tmp = ft_env_lststr(g_d.tmp_list, name);
		if (tmp)
		{
			ft_putstr_fd("tmp : ", 1); ft_putstr_fd(tmp->name, 1); ft_putchar_fd(10, 1);
			ft_env_lstadd_back(&g_d.env_list, tmp); // Utiliser un tampon
			ft_env_lstdelone(tmp, free);
		}
	}
}

void	tmp_var(char *name, char *content)
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
			tmp->content = ft_strdup(content); // D'abord vider la variable
		}
	}
	else
	{
		tmp->content = ft_strdup(content); // D'abord vider la variable
	}
}

void	ft_env(void)
{
	t_env	*tmp;

	tmp = g_d.env_list;
	ft_putstr_fd("Maillon reçu dans env : ", 1);
	ft_putstr_fd(tmp->name, 1);
	ft_putchar_fd(10, 1);
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

