/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:16:31 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/07 16:16:34 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	init_data(t_data *d)
{
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (-19);
	d->s_free = -1;
	d->all = (t_all *)malloc(sizeof(t_all));
	if (!d->all)
		return (-19);
	d->s_free = 1;
	d->all->tab_cmd = (char **)malloc(sizeof(char *));
	if (!d->all->tab_cmd)
		return (-19);
	d->s_free = 2;
	printf("\033[H\033[J");
	printf(SCREEN);
	return (0);
}

// t_list	*create_(char **env)
// {
// 	int		i;
// 	t_list	*env_list;

// 	i = 0;
// 	env_list = ft_lstnew(keep_strt(env[i]), keep_end(env[i]));
// 	i++;
// 	while (env[i])
// 	{
// 		ft_lstadd_back(&env_list, ft_lstnew(keep_strt(env[i]), keep_end(env[i])));
// 		i++;
// 	}
// 	ft_lstadd_back(&env_list, ft_lstnew(NULL, NULL));
// 	return (env_list);
// }
