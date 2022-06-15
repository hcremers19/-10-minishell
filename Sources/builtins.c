/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/15 12:26:14 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// void	ft_exit(void)
// {
// 	exit(EXIT_SUCCESS);
// } // À élaborer

// void	ft_unset(t_env *env_list, char *name)
// {
// 	ft_lstdelone(env_list, ft_lststr(env_list, name));
// }

void	ft_export(char *name)
{
	ft_env_lstadd_back(&d.env_list, ft_env_lststr(d.tmp_list, name));
	ft_env_lstdelone(ft_env_lststr(d.tmp_list, name), free);
}	// Normalement pas d'erreur à gérer mais attention de ne pas ajouter une variable vide à l'environnement

// void	tmp_var(t_env *tmp_list, char *name, char *content)
// {
// 	ft_lstadd_front(&tmp_list, ft_lstnew(name, content));
// }

void	ft_env(void)
{
	while (d.env_list->name || d.env_list->content)
	{
		printf("%s=%s\n", d.env_list->name, d.env_list->content);
		d.env_list = d.env_list->next;
	}
}

// void	ft_cd(char *path)
// {
// 	if (chdir(path) == -1)
// 		perror("chdir()");
// }

// void	ft_pwd(void)
// {
// 	char	cwd[PATH_MAX];

// 	if (getcwd(cwd, sizeof(cwd)) != NULL)
// 		printf("%s\n", cwd);
// 	// else
// 	// 	perror("getcwd()");
// }

// void	ft_echo(char *str, int n)
// {
// 	ft_putstr_fd(str, 1);
// 	if (!n)
// 		ft_putchar_fd('\n', 1);
// }
