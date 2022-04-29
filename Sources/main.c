/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/11 15:26:52 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*prompt(void)
{
	char	*output;

	output = ft_strjoin(getenv("USER="), ".minishell >> ");
	return (output);
}

int	take_input(char *str)
{
	char	*input;
	
	input = readline(prompt());
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		ft_strcpy(str, input);
		return (0);
	}
	return (1);
}

void print_dir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
}

void	init_screen(void)
{
	printf("\033[H\033[J");
	printf(SCREEN);
}

int	main(int ac, char **av, char **env)
{
	char	input[1000];

	(void)ac;
	(void)av;
	(void)env;
	init_screen();
	while (19)
	{
		//print_dir();
		take_input(input);
	}
	return (0);
}
