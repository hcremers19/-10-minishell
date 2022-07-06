/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:44:20 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 15:44:15 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_isfulldigit(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) || str[i] == 45)
			i++;
		else
			return (1);
	}
	return (0);
}

/*	--------------------------------------------------------------------------
**	Reproduce 'exit' built-in command's behaviour:
**	-----------------------------------------------------------------------	*/

void	ft_exit(t_one *cmd)
{
	if (len_tab(cmd->pars_tab) < 3)
	{
		ft_putstr_fd("exit\n", 1);
		if (cmd->pars_tab[1])
		{
			if (!ft_isfulldigit(cmd->pars_tab[1]))
				g_d.error_code = ft_atoi(cmd->pars_tab[1]);
			else
			{
				ft_putstr_fd("exit: ", 1);
				ft_putstr_fd(cmd->pars_tab[1], 1);
				ft_putstr_fd(": numeric argument required\n", 1);
				g_d.error_code = 255;
			}
		}
		global_exit();
	}
	else
	{
		g_d.s_err = 7;
		loop_exit();
		main_loop();
	}
}
