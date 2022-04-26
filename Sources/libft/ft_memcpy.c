/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:04:51 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/04 17:04:58 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	if (!dst && !src)
		return (0);
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (i < num)
	{
		dst2[i] = src2[i];
		i++;
	}
	dst = dst2;
	src = src2;
	return (dst);
}
