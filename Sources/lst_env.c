/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:14:46 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/28 11:37:20 by hcremers         ###   ########.fr       */
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
	// ft_putstr_fd("LstAddFront added element ", 1); ft_putstr_fd(new->name, 1); ft_putchar_fd(10, 1);
}

void	ft_env_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	// ft_putstr_fd("Delone deleted ", 1); ft_putstr_fd(lst->name, 1); ft_putchar_fd(10, 1);
	(del)(lst->name);
	lst->name = NULL;
	(del)(lst->content);
	lst->content = NULL;
	// free(lst);
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
