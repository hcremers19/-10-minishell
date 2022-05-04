/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:50:35 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/04 17:19:37 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int n)
{
	int		in;
	int		ih;
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
