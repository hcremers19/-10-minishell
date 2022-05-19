/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exepipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:59:47 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/19 10:59:49 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int execpipe(t_data *d, char **env)
{
    t_one   *tmp;

    tmp = d->all->first;
    while (d->all->first)
    {
        if (ft_pipe(d->all->first->pars_tab, d, env))
            return (-19);
        d->all->first = d->all->first->next;
    }
    d->all->first = tmp;
    return (0);
}
