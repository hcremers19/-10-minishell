/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:48:55 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/11 11:47:53 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
// #include "Mini_sheh/Includes/pipe.h"

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
		// g_datas.last_command_status = 1;
	}
}

void	ft_signal(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
}

// int	main(void)
// {
// 	pid_t	pid;
// 	int		sig;

// 	pid = getpid();
// 	printf("%d\n", pid);
// 	ft_signal();
// 	sig = -1;
// 	while (sig)
// 	{
// 		scanf("%d", &sig);
// 		if (sig == 1)
// 			kill(pid, SIGUSR1);
// 		if (sig == 2)
// 			kill(pid, SIGUSR2);
// 	}
// }
