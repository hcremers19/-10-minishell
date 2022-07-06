/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 14:11:40 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Calls for init_tab creation and create structure linked
	list where each structure is a command.
	---------------------------------------------------------	*/

t_one	*ft_pars(char *s)
{
	int		j;
	int		i;
	t_one	*tmp;

	i = 0;
	j = 0;
	g_d.all->init_tab = ft_pars_line(s);
	if (!g_d.all->init_tab)
		return (NULL);
	g_d.all->first = ft_calloc(1, sizeof(t_one));
	if (!g_d.all->first)
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
		return (ft_free_cmd_lst(g_d.all->first));
	return (g_d.all->first);
}

/*	---------------------------------------------------------
	Loops in ft_pars to create pars_tab (matrix which contains
	strings of the command and parameters) for each structure/
	command. J is incremmenting in init_tab.
	Ex.:
	Input 			=  env | grep USER | wc -l
	init_tab		= ([env], [|], [grep], [USER], [|], [wc], [-l])
	cmd[0]pars_tab 	= ([env])
	cmd[1]pars_tab 	= ([grep], [USER])
	cmd[2]pars_tab 	= ([wc], [-l])
	---------------------------------------------------------	*/

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
		{
			ft_free_cmd_lst(tmp);
			return (NULL);
		}
	}
	return (tmp);
}
