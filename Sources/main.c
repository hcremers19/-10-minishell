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
			free(d->all->tab_cmd);
		}
	}
	return (0);
}


int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	*d;
	t_list	*env_list;
	t_list	*tmp_list;

	(void)ac;
	(void)av;
	(void)env;
	d = NULL;
	if (init_data(d))
		ft_error(d, 12);
	ft_signal();
	env_list = create_env(env);
	tmp_list = ft_lstnew(NULL, NULL);
	while (19)
	{
		input = readline(prompt());
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			// d->all->tab_cmd = ft_pars(input);//d)
			// if (!d->all->tab_cmd)
			// 	perror(strerror(0));// num code?
			free(input);
		}
	}
	return (0);
}
