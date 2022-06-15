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
	tcsetattr(0, TCSANOW, &d.new);
	if (d.s_free > 0)
	{
		ft_free_tab(d.env_tab);
		if (d.s_free > 2)
		{
			ft_free_lst(d.env_list);
			if (d.tmp_list)
				ft_free_lst(d.tmp_list);
			if (d.s_free > 4)
			{
				free(d.all);
				if (d.s_free > 6)
					free(d.all->init_tab);
			}
			
		}
	}
	if (d.s_free < 8)
	{
		perror(strerror(d.s_err));
		exit (1);
	}
}

void	loop_exit(void)
{
	if (d.s_free == 11)
		free(d.all->init_tab);
	else if (d.s_free > 12)
	{
		ft_free_tab(d.all->init_tab);
		if (d.s_free > 14)
			free(d.all->first);
		else if (d.s_free > 16)
		{
			ft_free_one(d.all->first);
		}
	}
/////////////////////////////////////////////////////////
	if (d.s_free > 8 && d.all->close_stat == 0)
		perror(strerror(d.s_err));
	else if (d.all->close_stat != 0)
		ft_putstr_fd("Input/output error: Non closed quotes\n", 1);
	init_data_bis(&d);
}








/////////////////////////////////////////////////////////
void	global_exit(void)
{
	init_exit();
	loop_exit();
	exit (1);
}
