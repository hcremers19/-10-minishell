/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:14:46 by acaillea          #+#    #+#             */
/*   Updated: 2022/06/27 15:33:26 by hcremers         ###   ########.fr       */
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
	ft_putstr_fd("LstAddFront added element ", 1); ft_putstr_fd(new->name, 1); ft_putchar_fd(10, 1);
}

void	ft_env_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_putstr_fd("Delone deleted ", 1); ft_putstr_fd(lst->name, 1); ft_putchar_fd(10, 1);
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

// void	ft_env_lstfreenull(t_env *env_list)
// {
// 	t_env	*tmp_list;
// 	t_env	*tmp_elmt;

// 	ft_putstr_fd("FreeNull : ", 1); ft_putstr_fd(env_list->name, 1); ft_putchar_fd(10, 1);
// 	tmp_list = env_list;
// 	while (env_list->next)
// 	{
// 		if (!env_list->next->name && !env_list->next->content)
// 		{
// 			tmp_elmt = env_list->next->next;
// 			ft_putstr_fd("TmpElmt : ", 1); ft_putstr_fd(tmp_elmt->name, 1); ft_putchar_fd(10, 1);
// 			ft_putstr_fd("NextNext : ", 1); ft_putstr_fd(env_list->next->next->name, 1); ft_putchar_fd(10, 1);
// 			free(env_list->next->next);
// 			env_list->next = tmp_elmt;
// 			return ;
// 		}
// 		else
// 			env_list = env_list->next;
// 	}
// 	env_list = tmp_list;
// }
