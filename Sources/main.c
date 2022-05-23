/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/14 13:13:57 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_error(t_data *d, int e)
{
	perror(strerror(e));
	if (d->s_free > 0)
	{
		free(d->all);
		if (d->s_free > 1)
		{
			ft_free_tab(d->all->init_tab);
		}
	}
	free(d);
	return (0);
}

int	ft_pre_malloc_error(int e)
{
	perror(strerror(e));
	return (0);
}

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
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			if (!ft_pars(input, d))
				return (ft_error(d, 1));//code ?
			////////////////////////////////////////////////
			////// temporaire
			int i;
			int j = 0;
			while (d->all->first)
			{
				printf("==============\n");
				i = 0;
				while (d->all->first->pars_tab[i])
				{
					printf("PARS[%d] -> %d = %s\n", j, i, d->all->first->pars_tab[i]);
					// printf("type= %d\n", d->all->first->type);
					i++;
				}
				printf("---------------\n");
				d->all->first = d->all->first->next;
				j++;
			}
			//////////// fin temporaire
			/////////////////////////////////////////////
			// if (execpipe(d, env))
			// 	return (ft_error(d, 0));//code ?
		}
		free(input);
	}
	return (0);
}
