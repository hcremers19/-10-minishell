/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/06 14:20:50 by hcremers         ###   ########.fr       */
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

// void	ft_export(t_env *env_list, t_env *tmp_list, char *name)
// {
// 	ft_lstadd_back(&env_list, ft_lststr(tmp_list, name));
// 	ft_lstdelone(tmp_list, ft_lststr(tmp_list, name));
// }

// void	tmp_var(t_env *tmp_list, char *name, char *content)
// {
// 	ft_lstadd_front(&tmp_list, ft_lstnew(name, content));
// }

// void	ft_env(t_env *env_list)
// {
// 	while (env_list->next)
// 	{
// 		printf("%s=%s\n", env_list->name, env_list->content);
// 		env_list = env_list->next;
// 	}
// }

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
// } // Ne supporte pas encore les variables d'environnement, si c'est ici qu'il faut les gérer
