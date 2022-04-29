/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _split.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:24:12 by acaillea          #+#    #+#             */
/*   Updated: 2021/10/16 17:16:49 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_wolloc(char const *s, char c)
{
	int	i;
	int	nb;
	int	size;

	i = 0;
	nb = 0;
	if (s[0] == '\0')
		return (0);
	size = ft_strlen(s) - 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			nb++;
		i++;
	}
	if (s[0] == c && s[size] == c)
		nb--;
	else if (s[0] != c && s[size] != c)
		nb++;
	return (nb);
}

int	ft_elen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_free(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j && tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char **) * (ft_wolloc(s, c) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	j = -1;
	if (s[0] != c && s[0] != '\0')
		tab[++j] = ft_substr(s, 0, ft_elen(s, c, 0));
	while (s[++i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
		{
			tab[++j] = ft_substr(s, i + 1, ft_elen(s, c, i + 1));
			if (!tab[j])
				return (ft_free(tab, j));
			i += ft_elen(s, c, i + 1);
		}
	}
	tab[++j] = NULL;
	return (tab);
}
