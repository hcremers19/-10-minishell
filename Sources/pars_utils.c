/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:17:44 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/11 12:07:00 by hcremers         ###   ########.fr       */
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

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	len_tab_string(char **tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab && tab[i])
	{
		count += ft_strlen(tab[i]);
		i++;
	}
	return (count);
}

char	**copy_line_tab(char **tab, t_data *d, int i)
{
	int		j;
	int		k;
	char	**init;

	j = i;
	k = 0;
	init = d->all->init_tab;
	while (init[j] && init[j][0] != '|') //&& ft_strlen(init[j]) != 1)
		j++;
	if (!j)
		return (NULL);
	j -= i;
	tab = (char **)malloc(sizeof(char *) * (j + 1));
	if (!tab)
		return (NULL);
	while (j)
	{
		tab[k] = (char *)malloc(sizeof(char) * (ft_strlen(init[i]) + 1));
		if (!tab[k])
			return (NULL);
		ft_strlcpy(tab[k], init[i], ft_strlen(init[i]));
		k++;
		i++;
		j--;
	}
	tab[k] = NULL;
	return (tab);
}

// int	nb_pipe(char **tab)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (tab && tab[i])
// 	{
// 		if (tab[i][0] == '|' && ft_strlen(tab[i]) == 1)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

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

// int	get_type(t_one *stru)
// {
// 	int	i;

// 	i = 0;
// 	while (stru->pars_tab[i])
// 	{
// 		if (stru->pars_tab[i][0] == 39)
// 			return (3);
// 		else if (stru->pars_tab[i][0] == 34)
// 		{
// 			if (check_c_in(stru->pars_tab[i], '$'))
// 				return (2);
// 			return (1);
// 		}
// 		else if (check_c_in(stru->pars_tab[i], '$'))
// 			return (4);
// 		i++;
// 	}
// 	return (0);
// }
