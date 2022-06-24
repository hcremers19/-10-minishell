/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:39:39 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/01 15:39:41 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	init_exit(void)
{
	tcsetattr(0, TCSANOW, &g_d.new);
	if (g_d.s_free > 0)
	{
		if (g_d.env_tab)
			ft_free_tab(g_d.env_tab);
		if (g_d.s_free > 2)
		{
			if (g_d.env_list)
				ft_free_lst(g_d.env_list);
			if (g_d.tmp_list)
				ft_free_lst(g_d.tmp_list);
			if (g_d.s_free > 4)
			{
				if (g_d.all)
					free(g_d.all);
				if (g_d.s_free > 6 && g_d.all->init_tab)
					free(g_d.all->init_tab);
			}
			
		}
	}
	if (g_d.s_free < 8)
	{
		perror(strerror(g_d.s_err));
		exit (1);
	}
}

void	loop_exit(void)
{
	if (g_d.s_free == 11 && g_d.all->init_tab)
		free(g_d.all->init_tab);
	else if (g_d.s_free > 12)
	{
		if (g_d.all->init_tab)
			ft_free_tab(g_d.all->init_tab);
		if (g_d.s_free > 14)
			free(g_d.all->first);
		else if (g_d.s_free > 16)
		{
			if (g_d.all->first)
				ft_free_cmd_lst(g_d.all->first);
		}
	}
/////////////////////////////////////////////////////////
	if (g_d.s_free > 8 && g_d.all->c_s == 0)
		perror(strerror(g_d.s_err));
	else if (g_d.all->c_s != 0)
		ft_putstr_fd("Input/output error: Non closed quotes\n", 1);
	init_data_bis(&g_d);
}






/////////////////////////////////////////////////////////
void	global_exit(void)
{
	init_exit();
	loop_exit();
	exit (1);
}
