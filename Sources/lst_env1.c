/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:33:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/30 17:44:39 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_env	*ft_env_lststr(t_env *lst, char *name)
{
	if (!name)
		return (NULL);
	while (lst)
	{
		if (!ft_strlcmp(lst->name, name))
		{
			return (lst);
		}
		else
			lst = lst->next;
	}
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
	return (elmt);
}

t_env	*ft_env_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
