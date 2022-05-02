/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/29 18:07:42 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int check_closing(char *s, char c, int i)
{
	int	j;

	j = ft_strlen(s);
	while (j > i)
	{
		if (s[j] == c)
			return (19);
		j--;
	}
	return (0);
}

static int	check(char *s)
{
	int	s;
	int	i;

	s = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '\\' && s[i + 1] == 39)
		{
			
		}
		if (s[i] != '\\' && s[i + 1] == 34)
		{

		}
	}
}

char	**ft_pars(char *str, t_data *d)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
}
