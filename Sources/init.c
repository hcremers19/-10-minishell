/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:16:31 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 15:20:22 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Switching termios, initiation of environnement tab and 
	environnment list.
	---------------------------------------------------------	*/

int	init_data(char **env, t_data *g_d)
{
	tcgetattr(0, &g_d->old);
	tcgetattr(0, &g_d->new);
	g_d->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &g_d->new);
	g_d->env_tab = cpy_tab(env, len_tab(env));
	if (!g_d->env_tab)
		return (-19);
	g_d->s_free = 1;
	if (create_env(env))
		return (-19);
	g_d->s_free = 3;
	g_d->tmp_list = ft_env_lstnew(NULL, NULL);
	g_d->all = (t_all *)malloc(sizeof(t_all));
	if (!g_d->all)
		return (-19);
	init_data_bis(g_d);
	init_sreen();
	g_d->s_free = 5;
	g_d->error_code = 0;
	return (0);
}

/*	---------------------------------------------------------
	Global_datas values initiation.
	---------------------------------------------------------	*/

void	init_data_bis(t_data *g_d)
{
	g_d->pid = 0;
	g_d->pos = 0;
	g_d->c_s = 0;
	g_d->s_err = 12;
	g_d->s_ex = 0;
	g_d->all->first = NULL;
}

/*	---------------------------------------------------------
	Clear screen and put header when programme launching 
	./minishell.
	---------------------------------------------------------	*/

void	init_sreen(void)
{
	ft_putstr_fd("\033[H\033[J", 1);
	ft_putstr_fd(SCREEN, 1);
}
