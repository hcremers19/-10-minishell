/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/07 10:24:01 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*init_loop(void)
{
	char	*prompt;
	char	*input;

	rl_on_new_line();
	prompt = ft_strjoin(getenv("USER="), MINI_PRPT);
	if (!prompt)
		return (NULL);
	g_d.s_free = 9;
	input = readline(prompt);
	add_history(input);
	free(prompt);
	return (input);
}
/////////////////// regarder free pipex avec wraloc
/// finir free

void	main_loop(void)
{
	char	*input;

	while (19)
	{
		ft_signal();
		input = init_loop();
		if (!input)
			global_exit();
		else if (input && only_space(input) && ft_strlen(input) != 0)
		{
			g_d.all->first = ft_pars(input);
			free(input);
			if (!g_d.all->first)
				global_exit();
			else if (g_d.c_s != 0 || g_d.s_ex)
					loop_exit();
			else if (execpipe())//// aucun retour != 0 pr le mmt
				global_exit();
		}
	}
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
	{
		perror(strerror(7));
		return (0);
	}
	g_d.s_free = -1;
	g_d.s_err = 12;
	if (init_data(env, &g_d))
		init_exit();
	main_loop();
	return (0);
}
