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

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = ft_strlen(src);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < ((size_t)dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
