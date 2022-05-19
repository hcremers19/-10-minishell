/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:19:32 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/06 14:20:40 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststr(t_list *lst, char *name) // À tester !
{
	t_list	*tmp;

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
