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

int	take_input(void)
{
	char	*input;
	
	input = readline(prompt());
	if (ft_strlen(input) != 0)
	{
		add_history(input);
		return (0);
	}
	return (1);
}


void	init_screen(void)
{
	printf("\033[H\033[J");
	printf(SCREEN);
}

int	main(int ac, char **av, char **env)
{

	(void)ac;
	(void)av;
	(void)env;
	init_screen();
	while (19)
	{
		take_input();
	}
	return (0);
}
