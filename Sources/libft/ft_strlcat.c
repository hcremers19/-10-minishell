/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:59:09 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/05 11:59:11 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = 0;
	s = 0;
	while (dst[d] && d < dstsize)
		d++;
	while (src[s])
	{
		if (d + s < dstsize - 1 && dstsize)
		{
			dst[d + i] = src[s];
			i++;
		}
		s++;
	}
	if (dstsize && d < dstsize)
		dst[d + i] = '\0';
	return (d + s);
}
