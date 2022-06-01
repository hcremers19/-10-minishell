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

int	ft_error(t_data *d, int e)
{
	perror(strerror(e));
	if (d->s_free > 0)
	{
		free(d->all);
		if (d->s_free > 1)
		{
			ft_free_tab(d->all->init_tab);
		}
	}
	free(d);
	return (0);
}

int	ft_pre_malloc_error(int e)
{
	perror(strerror(e));
	return (0);
}
