/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/11/10 13:52:38 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/minishell.h"

char	*get_prompt(void)
{
	char	*tmp;
	char	*tmp1;
	char	*ret;

	tmp = ft_strjoin("\x1b[31m", getenv("USER="));
	if (!tmp)
		return (NULL);
	tmp1 = ft_strjoin(tmp, ET);
	free(tmp);
	if (!tmp1)
		return (NULL);
	if (g_d.error_code)
		ret = ft_strjoin(tmp1, "\033[0;31mminishell >> \033[0;39m");
	else
		ret = ft_strjoin(tmp1, "\033[1;32mminishell >> \033[0;39m");
	free(tmp1);
	if (!ret)
		return (NULL);
	return (ret);
}

char	*init_loop(void)
{
	char	*prompt;
	char	*input;

	rl_on_new_line();
	prompt = get_prompt();
	if (!prompt)
		return (NULL);
	g_d.s_free = 7;
	input = readline(prompt);
	add_history(input);
	free(prompt);
	return (input);
}

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
			else
			{
				execpipe();
				loop_exit();
			}
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
