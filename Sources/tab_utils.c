/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:02:42 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 22:25:44 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Get number of strings in a matrix.
	---------------------------------------------------------	*/

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

/*	---------------------------------------------------------
	Get number of char in a matrix, all char of all string
	of the matrix cumulate.
	---------------------------------------------------------	*/

int	len_tab_string(char **tab)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tab && tab[++i])
	{
		count += ft_strlen(tab[i]);
	}
	return (count);
}

/*	---------------------------------------------------------
	Copies a matrix.
	---------------------------------------------------------	*/

char	**cpy_tab(char **in, int nb_line)
{
	char	**out;
	int		i;

	out = (char **)malloc(sizeof(char *) * (nb_line + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < nb_line)
	{
		out[i] = (char *)malloc(sizeof(char) * (ft_strlen(in[i]) + 1));
		if (!out[i])
		{
			ft_free_tab(out);
			return (NULL);
		}
		ft_strcpy(out[i], in[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}

/*	---------------------------------------------------------
	Joins strings of a matrix to return an unique string
	of it.
	---------------------------------------------------------	*/

char	*join_mat(char **tab)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(len_tab_string(tab) + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i <= len_tab(tab))
	{
		if (tab[i])
			str = ft_strcat(str, tab[i]);
		i++;
	}
	ft_free_tab(tab);
	return (str);
}
