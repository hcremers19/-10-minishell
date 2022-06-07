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
	t_data	*d;

	if (ac != 1)
		return (ft_pre_malloc_error(7));
	(void)av;
	// (void)env;
	d = init_data();
	if (!d)
		ft_error(d, 12);
	d->env_list = create_env(env);
	d->tmp_list = ft_lstnew(NULL, NULL);
	while (19)
	{
		ft_signal();
		input = readline(prompt());
		if (!input)
			exit(EXIT_SUCCESS);
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			if (!ft_pars(input, d))
				return (ft_error(d, 1));//code ?
			////////////////////////////////////////////////
			////// temporaire
			///////////////////////////////////////////////
			int i;
			int j = 0;
			while (d->all->first)
			{
				printf("==============\n");
				i = 0;
				while (d->all->first->pars_tab[i])
				{
					printf("PARS[%d] -> %d = %s\n", j, i, d->all->first->pars_tab[i]);
					i++;
				}
				printf("---------------\n");
				d->all->first = d->all->first->next;
				j++;
			}
			// int i = 0;
			// while (d->env_list)
			// {
			// 	printf("[%d] = %s = %s\n", i, d->env_list->name, d->env_list->content);
			// 	d->env_list = d->env_list->next;
			// 	i++;
			// }
			/////////////////////////////////////////////
			//////////// fin temporaire
			/////////////////////////////////////////////
			// if (execpipe(d, env))
			// 	return (ft_error(d, 0));//code ?
		}
		free(input);
	}
	return (0);
}
