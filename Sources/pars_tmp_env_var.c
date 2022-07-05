/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tmp_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:27 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 21:27:41 by hcremers         ###   ########.fr       */
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
	int		i;
	char	*tmp;

	i = 0;
	while (cmd->pars_tab[i])
	{
		if (check_c_in(cmd->pars_tab[i], '=') > 0)
		{
			g_d.s_ex = ft_strlcmp(cmd->pars_tab[0], "export");
			pre = keep_strt(cmd->pars_tab[i]);
			if (!pre)
				return (-19);
			aft = keep_end(cmd->pars_tab[i]);
			if (!aft)
				return (-19);
			tmp_var(pre, aft);
			tmp = keep_strt(cmd->pars_tab[i]);
			free(cmd->pars_tab[i]);
			cmd->pars_tab[i] = tmp;
		}
		i++;
	}
	return (0);
}
