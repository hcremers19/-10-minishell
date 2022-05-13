/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:16:31 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/07 16:16:34 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_data	*init_data(void)
{
	t_data	*d;

	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->s_free = -1;
	d->all = (t_all *)malloc(sizeof(t_all *));
	if (!d->all)
		return (NULL);
	d->s_free = 1;
	d->all->init_tab = (char **)malloc(sizeof(char *));
	if (!d->all->init_tab)
		return (NULL);
	d->s_free = 2;
	printf("\033[H\033[J");
	printf(SCREEN);
	return (d);
}
