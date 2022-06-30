/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/30 14:46:20 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_one	*ft_pars(char *s)
{
	int		j;
	int		i;
	t_one	*tmp;

	i = -1;
	j = 0;
	g_d.all->init_tab = ft_pars_line(s);
	g_d.all->first = ft_calloc(1, sizeof(t_one));
	if (!g_d.all->init_tab || !g_d.all->first)
		return (NULL);
	g_d.s_free = 13;
	tmp = g_d.all->first;
	while (tmp && ++i >= 0)
	{
		if (!ft_pars_loop(tmp, &j))
			return (NULL);
		tmp = tmp->next;
	}
	g_d.all->nb_cmd = i;
	if (init_cmds())
		return (NULL);
	return (g_d.all->first);
}

t_one	*ft_pars_loop(t_one *tmp, int *j)
{
	tmp->pars_tab = copy_line_tab(tmp->pars_tab, *j);
	if (!tmp->pars_tab)
		return (NULL);
	*j += len_tab(tmp->pars_tab) + 1;
	tmp->next = NULL;
	if (!(*j >= len_tab(g_d.all->init_tab)))
	{
		tmp->next = ft_calloc(1, sizeof(t_one));
		if (!tmp->next)
			return (NULL);
	}
	return (tmp);
}
