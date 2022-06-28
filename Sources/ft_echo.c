/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:09:24 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/28 11:56:32 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
	while (!ft_strncmp(pars_tab[i], "-n", 2))
		i++;
	while (pars_tab[i])
	{
		write_w_quotes(pars_tab[i]);
		i++;
		if (pars_tab[i])
			ft_putchar_fd(' ', 1);
	}
	if (ft_strncmp(pars_tab[1], "-n", 2))
		ft_putchar_fd('\n', 1);
}
