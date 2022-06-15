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

void	main_loop(void)
{
	char	*input;
	char	*prompt;

	while (19)
	{
		ft_signal();
		rl_on_new_line();
		prompt = ft_strjoin(getenv("USER="), MINI_PRPT);
		if (!prompt)
			init_exit();
		d.s_free = 9;
		input = readline(prompt);
		add_history(input);
		free(prompt);
		if (input && only_space(input) && ft_strlen(input) != 0)
		{
			d.all->first = ft_pars(input);
			free(input);
			if (!d.all->first)
				global_exit();
			else if (d.all->close_stat != 0)
				loop_exit();
			else if (execpipe())
				global_exit();
		}
		else if (!input)
		{
			d.s_err = 5;
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
	d.s_free = -1;
	d.s_err = 12;
	if (init_data(env, &d))
		init_exit();
	main_loop();
	return (0);
}

// 	//////////////////////////////////////////////////////////////////////////////////////////////
// 			int i;
// 			int j = 0;
// 			while (d.all->first)
// 			{
// 				printf("==============\n");
// 				i = 0;
// 				while (d.all->first->pars_tab[i])
// 				{
// 					printf("PARS[%d] -> %d = %s\n", j, i, d.all->first->pars_tab[i]);
// 					i++;
// 				}
// 				printf("---------------\n");
// 				d.all->first = d.all->first->next;
// 				j++;
// 			}
// 			// int i = 0;
// 			// while (d.env_list)
// 			// {
// 			// 	printf("[%d] = %s = %s\n", i, d.env_list->name, d.env_list->content);
// 			// 	d.env_list = d.env_list->next;
// 			// 	i++;
// 			// }
// //////////////////////////////////////////////////////////////////////////////////////////////