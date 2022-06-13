/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:16:31 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/07 16:16:34 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	init_data(char **env, t_data *d)
{
	d->s_free = -1;
	tcgetattr(0, &d->old);
	tcgetattr(0, &d->new);
	d->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &d->new);
	d->env_tab = cpy_tab(env, len_tab(env));
	if (!d->env_tab)
		return (-19);
	d->env_list = create_env(env);
	d->tmp_list = ft_env_lstnew(NULL, NULL);
	d->all = (t_all *)malloc(sizeof(t_all));
	if (!d->all)
		return (-19);
	d->s_free = 1;
	d->all->init_tab = (char **)malloc(sizeof(char *));
	if (!d->all->init_tab)
		return (-19);
	d->s_err = 12;
	d->s_free = 3;
	d->pid = 0;
	printf("\033[H\033[J");
	printf(SCREEN);
	return (0);
}
