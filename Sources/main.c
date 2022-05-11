/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/11 11:48:06 by hcremers         ###   ########.fr       */
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
		free(d);
		free(d->all);
		if (d->s_free > 1)
		{
			free(d->all->frst_tab);
		}
	}
	return (0);
}


int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	*d;

	(void)ac;
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
				return (ft_error(d, 0));//code ?
			int i = 0;
			while (d->all->frst_tab[i])
			{
				printf("[%d] = %s\n", i, d->all->frst_tab[i]);
				i++;
			}
		}
		free(input);
	}
	return (0);
}
