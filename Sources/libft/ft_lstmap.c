/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:32:18 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/26 10:32:20 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (0);
	lst2 = temp;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&lst2, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&lst2, temp);
	}
	return (lst2);
}
