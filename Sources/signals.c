/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:48:55 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/14 11:18:05 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	handler(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_redisplay();
	d.error_code = 1;
}

void	ft_signal(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}

// À réparer :
// - Ctrl + C sur une ligne non-vide
// - Ctrl + D après avoir fait plusieurs Ctrl + C ou Ctrl + '\'
