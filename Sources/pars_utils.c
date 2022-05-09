/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:44 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/09 14:17:52 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	nb_pipe(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab && tab[i])
	{
		if (tab[i][0] == '|' && ft_strlen(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

// char	**copy_tab(char **in)
// {
// 	int		i;
// 	int		j;
// 	char	**out;

// 	i = 0;
// 	j = 0;
// 	out = (char **)malloc(sizeof(char *) * (len_tab(in) + 1));
// 	if (!out)
// 		return (NULL);
// 	while (i < len_tab(in))
// 	{
// 		if (in[i][0] != '|' && ft_strlen(in[i]) != 1)
// 		{
// 			out[j] = (char *)malloc(sizeof(char) * (ft_strlen(in[i]) + 1));
// 			if (!out[j])
// 				return (NULL);
// 			ft_strlcpy(out[j], in[i], ft_strlen(in[i]));
// 			j++;
// 		}
// 		i++;
// 	}
// //	free matrice in ici ??????
// 	out[j] = 0;
// 	return (out);
// }

char	**copy_line_tab(char **tab, t_data *d, int i)
{
	int		j;

	while (d->all->frst_tab[i] && d->all->frst_tab[i][0] != '|' && ft_strlen(d->all->frst_tab[i]) != 1)
	{
		j = i;
		while (d->all->frst_tab[j] && d->all->frst_tab[j][0] != '|' && ft_strlen(d->all->frst_tab[j]) != 1)
			j++;
		tab = (char **)malloc(sizeof(char *) * (j + 1));
		if (!tab)
			return (NULL);
		while (j)
		{
			tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(d->all->frst_tab[i]) + 1));
			if (!tab[i])
				return (NULL);
			ft_strlcpy(tab[i], d->all->frst_tab[i], ft_strlen(d->all->frst_tab[i]));
			j--;
		}
		i++;
	}
	return (tab);
}
// ici ici iciiiiiiiiii : bus error
// comment conserver l'indice entre ft_pars et copy_line