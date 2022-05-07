/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:26:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/07 16:26:17 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*prompt(void)
{
	char	*output;

	output = ft_strjoin(getenv("USER="), "\033[0;31m.minishell >> \033[0;39m");
	return (output);
}

// void print_dir(void)
// {
// 	char cwd[1024];

// 	getcwd(cwd, sizeof(cwd));
// 	printf("%s", cwd);
// }
