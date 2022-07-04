/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:44:20 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/04 15:37:15 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_exit(t_one *cmd)
{
	if (len_tab(cmd->pars_tab) < 3)
	{
		ft_putstr_fd("exit\n", 1);
		if (cmd->pars_tab[1])
			g_d.error_code = ft_atoi(cmd->pars_tab[1]);
		global_exit();
		exit(0);
	}
	else
	{
		g_d.s_err = 7;
		loop_exit();
	}
}
