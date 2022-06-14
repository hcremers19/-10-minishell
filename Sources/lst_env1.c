/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:33:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/10 19:33:56 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_env	*ft_env_lststr(t_env *lst, char *name) // À tester !
{
	t_env	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (ft_strlen(lst->name) == ft_strlen(name)
			&& !ft_strncmp(lst->name, name, ft_strlen(lst->name)))
			return (lst);
		else
			lst = lst->next;
	}
	lst = tmp;
	return (0);
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
	elmt->next = 0;
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
