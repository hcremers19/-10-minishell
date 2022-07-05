/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tmp_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:27 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 20:24:35 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Put temporary variable (VAR_NAME'='VAR_CONTENT) into 
	temporary environnement linked list.
	---------------------------------------------------------	*/

int	check_tmp_env(t_one *cmd)
{
	char	*pre;
	char	*aft;

	if (len_tab(cmd->pars_tab) == 1 && (!g_d.all->first->next))
	{
		if (check_c_in(cmd->pars_tab[0], '=') >= 0)
		{
			g_d.s_ex = 1;
			pre = keep_strt(cmd->pars_tab[0]);
			if (!pre)
				return (-19);
			aft = keep_end(cmd->pars_tab[0]);
			if (!aft)
			{
				free(pre);
				return (-19);
			}
			if (tmp_var(pre, aft))
				return (ft_free_two(pre, aft));
		}
	}
	return (0);
}
