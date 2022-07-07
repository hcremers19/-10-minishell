/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:44 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/07 14:50:32 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Cut init_tab for each command structure to create, for
	each, its pars_tab.
	---------------------------------------------------------	*/

char	**copy_line_tab(char **tab, int i)
{
	int		j;
	int		k;
	char	**init;

	j = i;
	k = 0;
	init = g_d.all->init_tab;
	while (init[j] && init[j][0] != '|')
		j++;
	if (!j)
		return (NULL);
	j -= i - 1;
	tab = ft_calloc(j, sizeof(char *));
	if (!tab)
		return (NULL);
	while (--j)
	{
		tab[k] = ft_calloc(ft_strlen(init[i]) + 1, sizeof(char));
		if (!tab[k])
			return ((char **)ft_free_fct_tab(tab, NULL));
		ft_strlcpy(tab[k++], init[i], ft_strlen(init[i]));
		i++;
	}
	tab[k] = NULL;
	return (tab);
}

/*	---------------------------------------------------------
	Check if the string begins by simple or doubles quotes.
	If it does, it removes it.
	---------------------------------------------------------	*/

int	check_quotes(t_one *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (cmd->pars_tab[++i])
	{
		if (cmd->pars_tab[i][0] == '\"' && cmd->pars_tab[i])
		{
			tmp = ft_strtrim_c(cmd->pars_tab[i]);
			free(cmd->pars_tab[i]);
			cmd->pars_tab[i] = tmp;
		}
		else if (cmd->pars_tab[i][0] == '\'' && cmd->pars_tab[i])
		{
			tmp = ft_strtrim_c(cmd->pars_tab[i]);
			if (!tmp)
				return (-19);
			free(cmd->pars_tab[i]);
			cmd->pars_tab[i] = tmp;
		}
	}
	return (0);
}
