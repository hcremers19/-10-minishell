/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:50:35 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/06 18:50:37 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	in;
	size_t	ih;
	char	*hs;

	ih = 0;
	hs = (char *)haystack;
	if (!ft_strlen(needle))
		return (hs);
	if ((ft_strlen(haystack) < ft_strlen(needle)) || n < ft_strlen(needle))
		return (0);
	while (hs[ih] && ih <= n - ft_strlen(needle))
	{
		in = 0;
		while (needle[in] && (hs[ih + in] == needle[in]))
			in++;
		if (in == ft_strlen(needle))
			return (&hs[ih]);
		ih++;
	}
	return (0);
}
