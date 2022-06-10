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

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)av;
	if (ac != 1)
		return (ft_pre_malloc_error(7));
	if (init_data(env, &d))
		return (ft_free_exit());
	while (19)
	{
		ft_signal();
		rl_on_new_line();
		input = readline(prompt());
		add_history(input);
		if (input && only_space(input) && ft_strlen(input) != 0)
		{
			if (!ft_pars(input))
				return (ft_free_exit());
			free(input);
//////////////////////////////////////////////////////////////////////////////////////////////
			int i;
			int j = 0;
			while (d.all->first)
			{
				printf("==============\n");
				i = 0;
				while (d.all->first->pars_tab[i])
				{
					printf("PARS[%d] -> %d = %s\n", j, i, d.all->first->pars_tab[i]);
					i++;
				}
				printf("---------------\n");
				d.all->first = d.all->first->next;
				j++;
			}
			// int i = 0;
			// while (d.env_list)
			// {
			// 	printf("[%d] = %s = %s\n", i, d.env_list->name, d.env_list->content);
			// 	d.env_list = d.env_list->next;
			// 	i++;
			// }
//////////////////////////////////////////////////////////////////////////////////////////////
			// if (execpipe(env))
			// 	return (ft_free_exit(0));
		}
		else
			return (ft_basic_exit());
	}
	return (0);
}



