/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:44:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/26 13:44:58 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++j])
		s3[++i] = s1[j];
	j = -1;
	while (s2[++j])
		s3[++i] = s2[j];
	s3[i + 1] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
