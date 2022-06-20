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
	t_env	*tmp; // À tester 🤔

	tmp = ft_env_lststr(d.env_list, name);
	if (tmp)
	{
		free(tmp->content);
		tmp->content = ft_strdup(ft_env_lststr(d.tmp_list, name)->content);
	}
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

void	ft_echo(char **pars_tab)
{
	int i;

	i = 1;
	while (!ft_strncmp(pars_tab[i], "-n", 2))
		i++;
	while (pars_tab[i])
	{
		ft_putstr_fd(pars_tab[i], 1);
		i++;
		if (pars_tab[i])
			ft_putchar_fd(' ', 1);
	}
	if (ft_strncmp(pars_tab[1], "-n", 2))
		ft_putchar_fd('\n', 1);
}
