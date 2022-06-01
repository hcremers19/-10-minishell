/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:52:13 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/06 17:52:16 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!n)
// 		return (0);
// 	while (s2[i] && s1[i] && s1[i] == s2[i] && i < n - 1)
// 		i++;
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1_str;
	char	*s2_str;
	size_t	i;

	s1_str = (char *)s1;
	s2_str = (char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_str[i] && s2_str[i] && s1_str[i] == s2_str[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1_str[i] - (unsigned char)s2_str[i]);
}
