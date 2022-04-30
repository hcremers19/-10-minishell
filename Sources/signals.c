/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:48:55 by hcremers          #+#    #+#             */
/*   Updated: 2022/04/30 14:58:34 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
// #include "Mini_sheh/Includes/pipe.h"

void	handler(int sig)
{
	printf(" Signal %d recieved\n", sig);
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

// kill -TERM	->	15 (SIGTERM)
// kill -CONT	->	19 (SIGCONT)