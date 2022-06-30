/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:44 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/30 14:56:13 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	nb_spec_char(char **tab, int c, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (len != 2 && len != 1)
		return (-19);
	while (tab && tab[i])
	{
		if (len == 2)
		{
			if (tab[i][0] == c && tab[i][1] == c && ft_strlen(tab[i]) == 2)
				count++;
		}
		else if (len == 1)
		{
			if (tab[i][0] == c && ft_strlen(tab[i]) == 1)
				count++;
		}
		i++;
	}
	return (count);
}

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
			return (NULL);
		ft_strlcpy(tab[k++], init[i], ft_strlen(init[i]));
		i++;
	}
	tab[k] = NULL;
	return (tab);
}
