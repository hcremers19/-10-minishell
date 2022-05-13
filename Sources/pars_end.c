/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:38:16 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/13 20:38:18 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	init_cmd(t_data *d, int nb)
{
	int	i;
	t_one	*tmp;

	i = 0;
	tmp = d->all->first;
	while (d->all->first)
	{
		d->all->first->pos = nb - i - 1;
		d->all->first->type = get_type(d->all->first);
		// if (d->all->first->type == 2 || d->all->first->type == 4)
		// {
		// 	check_env_var(d->all->first);
		// }
		d->all->first = d->all->first->next;
		i++;
	}
	d->all->first = tmp;
}

int	get_type(t_one *stru)
{
	int	i;
	int	j;

	i = 1;
	while (stru->pars_tab[i])
	{
		if (stru->pars_tab[i][0] == 39)
			return (3);
		else if (stru->pars_tab[i][0] == 34)
		{
			j = 0;
			while (stru->pars_tab[i][j])
			{
				if (stru->pars_tab[i][j] == 36)
					return (2);
				j++;
			}
			return (1);
		}
		else if (check_c_in(stru->pars_tab[i], '$'))
			return (4);
		i++;
	}
	return (0);
}


// int	check_env_var(t_one *stru)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	while (stru->pars_tab[i])
// 	{
// 		j = 0;
// 		while(stru->pars_tab[i][j])
// 		{
// 			if (stru->pars_tab[i][j] == 36)
// 			{

// 				while ()
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
