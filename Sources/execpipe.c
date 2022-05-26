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

// int execpipe(t_data *d, char **env)
// {
//     t_one   *tmp;
//     char *tab;
//     int i;

//     i = 0;
//     tmp = d->all->first;
//     while (d->all->first)
//     {
//         d->all->first == copy_line_tab(tab, d->all->first, i);
//         if (builtin_cmds != 0)
//         {

//         }


//         // if (ft_pipe(d->all->first->pars_tab, d, env))
//         //     return (-19);
//         // d->all->first = d->all->first->next;
//     }
//     d->all->first = tmp;
//     return (0);
// }

int builtin_cmds_env(t_one *cmd)
{
    if (!ft_strncmp("export", cmd->cmd, 6))
        ft_export(ft_pars(cmd->all), cmd->all);
    else if(!ft_strncmp("cd", cmd->cmd, 2))
        ft_cd(ft_pars(cmd->all), cmd->all);
    else if(!ft_strncmp("unset", cmd->cmd, 5))
        ft_unset(ft_pars(cmd->all), cmd->all);
    else
        return (1);
    return (0);
    
}

int builtin_cmds(t_one *cmd)
{
    if (!ft_strncmp("exit", cmd->cmd, 4))
        ft_exit();
    else if (!ft_strncmp("pwd", cmd->cmd, 3))
        ft_pwd();
    else if (!ft_strncmp("env", cmd->cmd, 3))
        ft_env(cmd->all);
    else if (!ft_strncmp("echo", cmd->cmd, 4))
        ft_echo(ft_pars(cmd->all), cmd->all);
    else 
        return (1);
    return (0);
}

int check_builtin(t_one *cmd)
{
    return (!ft_strncmp("export", cmd->cmd, 6))
        || (!ft_strncmp("cd", cmd->cmd, 2))
        || (!ft_strncmp("unset", cmd->cmd, 5))
        || (!ft_strncmp("exit", cmd->cmd, 4))
        || (!ft_strncmp("pwd", cmd->cmd, 3))
        || (!ft_strncmp("env", cmd->cmd, 3))
        || (!ft_strncmp("echo", cmd->cmd, 4)));
}