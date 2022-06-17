/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:38:59 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/01 15:39:01 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = len_tab(tab) - 1;
	while (i >= 0)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	if (tab)
		free(tab);
}

void	ft_free_lst(t_env *list)
{
	t_env	*tmp;

	while (list->next)
	{
		tmp = list;
		if (tmp->content)
			free(tmp->content);
		if (tmp->name)
			free(tmp->name);
		list = tmp->next;
		if (tmp)
			free(tmp);
	}
	// if (list->content)
	// 	free(list->content);
	// if (list->name)
	// 	free(list->name);
	// if (list)
	// 	free(list);
}

void	ft_free_cmd_lst(t_one *cmd)
{
	int		i;
	t_one	*tmp;

	i = 0;
	while (cmd->next)
	{
		tmp = cmd;
		if (cmd->pars_tab)
			ft_free_tab(cmd->pars_tab);
		cmd = tmp->next;
		if (tmp)
			free(tmp);
	}
}

// void	ft_free_one()/////////////////////// free one commande