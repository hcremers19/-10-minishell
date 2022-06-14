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

int	init_exit(void)
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
				free(d.all)
				if (d.s_free > 6)
					free(d.all->init_tab);
			}
			
		}
	}
	if (d.s_err && d.all->close_stat == 0)
		perror(strerror(d.s_err));
	return (0);
}

int	loop_exit(void)
{
	if (d.s_err && d.all->close_stat == 0)
		perror(strerror(d.s_err));
	return (0);
}

int	global_exit(void)
{
	init_exit();
	lopp_exit();
	return (0);
}
