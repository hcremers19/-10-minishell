/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/15 16:17:12 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// void	ft_exit(void)
// {
// 	exit(EXIT_SUCCESS);
// } // À élaborer

void	ft_unset(char *name)
{
	ft_env_lstdelone(ft_env_lststr(d.env_list, name), free);
	ft_env_lstfreenull(d.env_list);
}	// Normalement pas de gestion d'erreur parce que la fonction ne devrait juste rien faire si elle ne trouve pas ce qu'elle cherche

void	ft_export(char *name)
{
	ft_env_lstadd_back(&d.env_list, ft_env_lststr(d.tmp_list, name));
	ft_env_lstdelone(ft_env_lststr(d.tmp_list, name), free);
	ft_env_lstfreenull(d.tmp_list);
}	// Normalement pas de gestion d'erreur parce que la fonction ne devrait juste rien faire si elle ne trouve pas ce qu'elle cherche

void	tmp_var(char *name, char *content)
{
	ft_env_lstadd_front(&d.tmp_list, ft_env_lstnew(name, content));
}

void	ft_env(void)
{
	t_env	*tmp;

	tmp = d.env_list;
	while (d.env_list->next)
	{
		if (d.env_list->name || d.env_list->content)
		{
			ft_putstr_fd(d.env_list->name, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(d.env_list->content, 1);
			ft_putchar_fd(10, 1);
		}
		d.env_list = d.env_list->next;
	}
	ft_putstr_fd(d.env_list->name, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(d.env_list->content, 1);
	ft_putchar_fd(10, 1);
	d.env_list = tmp;
}

void	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
}	// Aller voir le pwd d'Hugo si ça vaut la peine d'en faire un plus complexe

// void	ft_echo(char *str, int n)
// {
// 	ft_putstr_fd(str, 1);
// 	if (!n)
// 		ft_putchar_fd('\n', 1);
// }
