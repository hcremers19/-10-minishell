/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:44 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 19:11:04 by acaillea         ###   ########.fr       */
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
