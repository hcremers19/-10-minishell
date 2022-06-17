/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:16:31 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/15 10:44:26 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	init_data(char **env, t_data *d)
{
	tcgetattr(0, &d->old);
	tcgetattr(0, &d->new);
	d->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &d->new);
	d->env_tab = cpy_tab(env, len_tab(env));
	if (!d->env_tab)
		return (-19);
	d->s_free = 1;
	if (create_env(env))
		return (-19);
	d->s_free = 3;
	d->tmp_list = ft_env_lstnew(NULL, NULL);
	d->all = (t_all *)malloc(sizeof(t_all));
	if (!d->all)
		return (-19);
	d->s_free = 5;
	d->all->init_tab = (char **)malloc(sizeof(char *));
	if (!d->all->init_tab)
		return (-19);
	init_data_bis(d);
	init_sreen();
	return (0);
}

void	init_data_bis(t_data *d)
{
	d->s_free = 7;
	d->pid = 0;
	d->all->close_stat = 0;
	d->s_err = 12;
	
}

void	init_sreen(void)
{
	ft_putstr_fd("\033[H\033[J", 1);
	ft_putstr_fd(SCREEN, 1);
}
