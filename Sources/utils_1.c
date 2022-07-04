/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:20:59 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/04 19:09:35 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Check if the string s is only filled whit space (32) and
	tab (9). Returns 1 if it does not.
	---------------------------------------------------------	*/

int	only_space(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] == 9 || s[i] == 32)
		i++;
	if (i < len)
		return (1);
	return (0);
}

/*	---------------------------------------------------------
	Appends string src to the end of dst. No len specified.
	---------------------------------------------------------	*/

char	*ft_strcat(char *dest, char *src)
{
	unsigned int		i;
	unsigned int		j;
	char				*destination;

	if (!dest)
		return (src);
	i = ft_strlen(dest);
	j = 0;
	destination = dest;
	while (src[j] != '\0')
	{
		destination[i] = src[j];
		j++;
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
