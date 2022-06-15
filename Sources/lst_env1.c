/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:33:55 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/15 16:00:57 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_env	*ft_env_lststr(t_env *lst, char *name)
{
	t_env	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (!ft_strncmp(lst->name, name, ft_strlen(lst->name)))
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
