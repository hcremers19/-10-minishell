/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:26:51 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/04 17:30:15 by hcremers         ###   ########.fr       */
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
	}
	return (0);
}

char	*prompt(void)
{
	char	*output;

	output = ft_strjoin(getenv("USER="), "\033[0;31m.minishell >> \033[0;39m");
	return (output);
}

// void print_dir(void)
// {
// 	char cwd[1024];

// 	getcwd(cwd, sizeof(cwd));
// 	printf("%s", cwd);
// }

int	init(t_data	*d)
{
	t_all	*all;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (-19);
	d->s_free = -1;
	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (-19);
	d->s_free = 1;
	d->all = all;
	printf("\033[H\033[J");
	printf(SCREEN);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_data	*d;

	(void)ac;
	(void)av;
	// (void)env;
	d = NULL;
	if (init(d))
		ft_error(d, 12);
	ft_signal();
	get_env(env);
	while (19)
	{
		input = readline(prompt());
		if (ft_strlen(input) != 0)
		{
			add_history(input);
			// if (!ft_pars(input, d))
			// 	perror(strerror(0));// num code?
			free(input);
		}
	}
	// printf("%s\n", env[5]);
	return (0);
}
