/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:54:44 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/04 17:21:38 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (0);
	if (len > (ft_strlen(s) - start - 1))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= start && j < len)
			str[j++] = s[i];
	str[j] = 0;
	return (str);
}
