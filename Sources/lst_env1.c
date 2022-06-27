/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:33:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/27 12:21:54 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_env	*ft_env_lststr(t_env *lst, char *name)
{
	t_env	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, name, ft_strlen(tmp->name)))
		{
			ft_putstr_fd("LstStr found ", 1); ft_putstr_fd(tmp->name, 1); ft_putchar_fd(10, 1);
			return (tmp);
		}
		else
			tmp = tmp->next;
	}
	ft_putstr_fd("LstStr didn't find ", 1); ft_putstr_fd(name, 1); ft_putchar_fd(10, 1);
	return (NULL);
}

t_env	*ft_env_lstnew(char *name, char *content)
{
	t_env	*elmt;

	if (!name || !content)
		return (NULL);
	elmt = (t_env *)malloc(sizeof(t_env));
	if (!elmt)
		return (NULL);
	elmt->name = name;
	elmt->content = content;
	elmt->next = NULL;
	ft_putstr_fd("LstNew created element ", 1); ft_putstr_fd(name, 1); ft_putchar_fd(10, 1);
	return (elmt);
}

t_env	*ft_env_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
