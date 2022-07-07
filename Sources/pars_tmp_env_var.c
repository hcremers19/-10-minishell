/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tmp_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:35:27 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/07 12:31:10 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Put temporary variable (VAR_NAME'='VAR_CONTENT) into 
	temporary environnement linked list.
	---------------------------------------------------------	*/

void	check_tmp_env_bis(t_one *cmd, char *pre, char *aft, int i)
{
	char	*tmp;

	tmp_var(pre, aft);
	tmp = keep_strt(cmd->pars_tab[i]);
	free(cmd->pars_tab[i]);
	cmd->pars_tab[i] = tmp;
}

int	check_tmp_env(t_one *cmd)
{
	char	*pre;
	char	*aft;
	int		i;

	i = -1;
	while (cmd->pars_tab[++i])
	{
		if (check_c_in(cmd->pars_tab[i], '=') > 0)
		{
			g_d.s_ex = ft_strlcmp(cmd->pars_tab[0], "export");
			pre = keep_strt(cmd->pars_tab[i]);
			if (!pre)
				return (-19);
			aft = keep_end(cmd->pars_tab[i]);
			if (!aft)
				return (ft_free_two(pre, aft));
			if (check_c_in(cmd->pars_tab[0], '=') > 0 \
				|| (!ft_strlcmp(cmd->pars_tab[0], "export")))
				check_tmp_env_bis(cmd, pre, aft, i);
			else
				ft_free_two(pre, aft);
		}
	}
	return (0);
}
