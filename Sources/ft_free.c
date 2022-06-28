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
	i = 0;
	while (i < len_tab(tab))
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
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

void	*ft_free_cmd_lst(t_one *cmd)
{
	int		i;

	i = len_tab(cmd->pars_tab) - 1;
	while (i >= 0)
	{
		if (cmd->pars_tab[i])
			free(cmd->pars_tab[i]);
		i--;
	}
	if (cmd->pars_tab)
		free(cmd->pars_tab);
	if (cmd->infile > 0)
		close(cmd->infile);
	if (cmd->outfile > 1)
		close(cmd->outfile);
	if (cmd->next)
		ft_free_cmd_lst(cmd->next);
	if (cmd)
		free(cmd);
	return (NULL);
}
