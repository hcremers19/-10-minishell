/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:14:46 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/15 12:25:47 by hcremers         ###   ########.fr       */
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

void	ft_env_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(lst->name);
	(del)(lst->content);
	free(lst);
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
