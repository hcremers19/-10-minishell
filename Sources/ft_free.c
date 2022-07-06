/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:38:59 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/06 14:00:00 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Free matrix.
	---------------------------------------------------------	*/

void	ft_free_tab(char **tab)
{
	int	i;
	int	len;

	i = 0;
	if (!tab)
		return ;
	len = len_tab(tab);
	while (i < len)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	tab = NULL;
}

/*	---------------------------------------------------------
	Free environnement and temporary environnement linked list.
	---------------------------------------------------------	*/

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
	if (list->content)
		free(list->content);
	if (list->name)
		free(list->name);
	if (list)
		free(list);
}

/*	---------------------------------------------------------
	Free command structure linked list.
	---------------------------------------------------------	*/

void	*ft_free_cmd_lst(t_one *cmd)
{
	int		i;
	int		j;

	i = len_tab(cmd->pars_tab);
	j = -1;
	while (++j < i && cmd->pars_tab[j])
		free(cmd->pars_tab[j]);
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

/*	---------------------------------------------------------
	Free matrix and tmp for parsing exception. Returns NULL.
	---------------------------------------------------------	*/

char	*ft_free_fct_tab(char **tab, char *tmp)
{
	int	i;
	int	len;

	i = 0;
	if (!tab)
		return (NULL);
	len = len_tab(tab);
	while (i < len)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	if (tmp)
		free(tmp);
	return (NULL);
}

/*	---------------------------------------------------------
	Free two strings.
	---------------------------------------------------------	*/

int	ft_free_two(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (-19);
}
