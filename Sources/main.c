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

int	main_loop(void)
{
	char	*input;
	char	*prompt;

	while (19)
	{
		ft_signal();
		rl_on_new_line();
		prompt = ft_strjoin(getenv("USER="), "\033[0;31m.minishell >> \033[0;39m");
		input = readline(prompt);
		add_history(input);
		free(prompt);
		if (input && only_space(input) && ft_strlen(input) != 0)
		{
			d.all->first = ft_pars(input);
			free(input);
			if (!d.all->first)
				return (ft_free_exit());
			/*else if*/if (d.all->close_stat != 0)
			{
				printf("Input/output error: Non closed quotes\n");
				ft_free_exit();
			}
			else if (execpipe())
			{
				d.s_err = 0;
				ft_free_exit();
			}
		}
		else if (!input)
		{
			d.s_err = 5;
			return (ft_init_exit());
		}
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	d.s_free = -1;
	if (ac != 1)
	{
		perror(strerror(7));
		return (0);
	}
	if (init_data(env, &d))
		return (ft_init_exit());
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