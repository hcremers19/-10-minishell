/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/06 14:12:50 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
	ft_signal();
	d->env_list = create_env(env);
	d->tmp_list = ft_lstnew(NULL, NULL);
	while (19)
	{
		input = readline(prompt());
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			d->all->frst_tab = ft_pars_line(input);//d)
			if (!d->all->frst_tab)
				perror(strerror(0));// num code?
			int i = 0;
			while (d->all->frst_tab[i])
			{
				printf("[%d] %d = %s\n", i, ft_strlen(d->all->frst_tab[i]),d->all->frst_tab[i]);
				i++;
			}
			free(input);
		}
	}
	return (0);
}
