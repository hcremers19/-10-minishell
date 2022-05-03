/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:07:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/04/29 18:07:42 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int check_in(char *s)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (s && s[i])
	{
		if (s[i] == '\'')
			stat = 1;
		if (s[i] == '\"')
			stat = 2;
		i++;
	}
	return (stat);
}

// // static int	check(char *s)
// // {
// // 	int	s;
// // 	int	i;

// // 	s = 0;
// // 	i = 0;
// // 	while (s[i])
// // 	{
// // 		if (s[i] != '\\' && s[i + 1] == 39)
// // 		{
			
// // 		}
// // 		if (s[i] != '\\' && s[i + 1] == 34)
// // 		{

// // 		}
// // 	}
// // }

char	**ft_pars(char *str, t_data *d)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	if (!str)
		return (NULL);
	s = check_in(str, '\'');
	d = check_in(str, '\"');

}

#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;

	printf("%s\n", av[1]);
	printf("%d\n", check_in(av[1], '\"'));
	printf("%d\n", check_in(av[1], '\''));
	return (0);
}