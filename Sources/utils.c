/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:44:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/04 19:04:07 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	Increments while char of a stirng is alphabetical.
	---------------------------------------------------------	*/

int	loop_while(char *str, int i)
{
	i++;
	while (str && str[i] && ft_isalpha(str[i]))
		i++;
	return (i);
}

/*	---------------------------------------------------------
	Copies the string src to dst. No len specified.
	---------------------------------------------------------	*/

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

/*	---------------------------------------------------------
	Check if c is present in str, returns it's position 
	or a negative if it do not.
	---------------------------------------------------------	*/

int	check_c_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-19);
}

/*	---------------------------------------------------------
	Counts the number of occurence of c in str.
	---------------------------------------------------------	*/

int	count_c_in(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
