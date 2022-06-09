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

int	ft_pre_malloc_error(int e)
{
	perror(strerror(e));
	return (0);
}

int	ft_basic_exit(void)
{
	ft_free_tab(d.env);
	ft_free_lst(d.env_list);
	if (d.tmp_list)
		ft_free_lst(d.tmp_list);
	tcsetattr(0, TCSANOW, &d.new);
	return (0);
}

int	ft_exit(int e)
{
	ft_basic_exit();
	if (d.s_free > 0)
	{
		free(d.all);
		if (d.s_free > 2)
		{
			ft_free_tab(d.all->init_tab);
		}
	}
}