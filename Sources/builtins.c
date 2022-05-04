/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:17:20 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/04 17:02:57 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_env(t_list *env_list)
{
	while (env_list->next)
	{
		printf("%s=%s\n", env_list->name, env_list->content);
		env_list = env_list->next;
	}
}

void	ft_cd(char *path)
{
	/*if (*/chdir(path)/* == -1)
		perror("chdir()")*/;
}

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	// else
	// 	perror("getcwd()");
}

void	ft_echo(char *str, int n)
{
	ft_putstr_fd(str, 1);
	if (!n)
		ft_putchar_fd('\n', 1);
} // Ne supporte pas encore les variables d'environnement, si c'est ici qu'il faut les gérer
