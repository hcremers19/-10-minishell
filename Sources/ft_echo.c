/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:09:24 by acaillea          #+#    #+#             */
/*   Updated: 2022/07/05 15:16:50 by hcremers         ###   ########.fr       */
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

/*	--------------------------------------------------------------------------
**	Reproduce 'echo' built-in command's behaviour:
**	Write the string(s) passed as argument(s) on stdout
**	The '-n' option prevents the function from printing the ending newline
**	character
**	-----------------------------------------------------------------------	*/

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
