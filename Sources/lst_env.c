/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:14:46 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/10 17:14:48 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_env_lstadd_front(t_env **lst, t_env *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = (*lst);
	*lst = new;
}

void	ft_env_lstdelone(t_env *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}

t_env	*ft_env_lstnew(char *name, char *content)
{
	t_env	*elmt;

	elmt = (t_env *)malloc(sizeof(t_env));
	if (!elmt)
		return (0);
	elmt->name = name;
	elmt->content = content;
	elmt->next = 0;
	return (elmt);
}

t_env	*ft_env_lstlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (*lst)
	{
		temp = ft_env_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

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
