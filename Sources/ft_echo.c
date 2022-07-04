/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:09:24 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/04 19:16:40 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	---------------------------------------------------------
	
	---------------------------------------------------------	*/

void	write_w_quotes(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '\"')
		while (str[++i] == '\"')
			;
	else if (str[i] == '\'')
		while (str[++i] == '\'')
			;
	len = ft_strlen(str) - i - 1;
	while (i <= len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_echo(char **pars_tab)
{
	int	i;

	i = 1;
	while (!ft_strlcmp(pars_tab[i], "-n"))
		i++;
	while (pars_tab[i])
	{
		write_w_quotes(pars_tab[i]);
		i++;
		if (pars_tab[i])
			ft_putchar_fd(' ', 1);
	}
	if (ft_strlcmp(pars_tab[1], "-n"))
		ft_putchar_fd('\n', 1);
	g_d.error_code = 0;
}
