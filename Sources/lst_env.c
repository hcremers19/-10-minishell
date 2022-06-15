/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:14:46 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/15 15:59:09 by hcremers         ###   ########.fr       */
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
	lst->name = NULL;
	(del)(lst->content);
	lst->content = NULL;
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

void	ft_env_lstfreenull(t_env *env_list)
{
	t_env	*maintmp;
	t_env	*tmp_tmp;

	maintmp = env_list;
	while (env_list->next)
	{
		if (!env_list->next->name && !env_list->next->content)
		{
			tmp_tmp = env_list->next->next;
			free(env_list->next->next);
			env_list->next = tmp_tmp;
		}
		else
			env_list = env_list->next;
	}
	env_list = maintmp;
}
