/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:44:20 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/24 17:44:22 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_exit(t_one *cmd)
{
	if (len_tab(cmd->pars_tab) < 3)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
		// global_exit();
	}
	else
	{
		g_d.s_err = 7;
		loop_exit();
	}
}
