/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:39:39 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 15:43:14 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Exit for init_data elements. Free environnement, temporary 
	environnement linked lis and Global_data->all pointer.
	---------------------------------------------------------	*/

void	init_exit(void)
{
	tcsetattr(0, TCSANOW, &g_d.new);
	if (g_d.env_tab)
		ft_free_tab(g_d.env_tab);
	if (g_d.s_free > 2)
	{
		if (g_d.env_list)
			ft_free_lst(g_d.env_list);
		if (g_d.tmp_list)
			ft_free_lst(g_d.tmp_list);
		if (g_d.s_free > 4)
			if (g_d.all)
				free(g_d.all);
	}
	if (g_d.s_free < 6)
	{
		perror(strerror(g_d.s_err));
		exit (0);
	}
}

/*	---------------------------------------------------------
	Exit for main_loop. Free all matrix and command linked
	list after it has been executed. 
	Free for a new line of command in minishell.
	---------------------------------------------------------	*/

void	loop_exit(void)
{
	if (g_d.s_free == 9 && g_d.all->init_tab)
		free(g_d.all->init_tab);
	else if (g_d.s_free > 10)
	{
		ft_free_tab(g_d.all->init_tab);
		if (g_d.s_free > 12 && g_d.all->first)
			ft_free_cmd_lst(g_d.all->first);
	}
	if (g_d.s_ex)
		return (init_data_bis(&g_d));
	else if (g_d.s_free > 8 && g_d.c_s == 0 && g_d.s_err != 12)
		perror(strerror(g_d.s_err));
	else if (g_d.c_s != 0)
		ft_putstr_fd("Input/output error: Non closed quotes\n", 1);
	init_data_bis(&g_d);
}

/*	---------------------------------------------------------
	General exit. Free all. Generally in case of memory 
	allocation error, command "exit" or CTRL + D.
	---------------------------------------------------------	*/

void	global_exit(void)
{
	loop_exit();
	init_exit();
	exit (g_d.error_code);
}
