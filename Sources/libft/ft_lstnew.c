/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:45:47 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/25 14:51:50 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elmt;

	elmt = (t_list *)malloc(sizeof(t_list));
	if (!elmt)
		return (0);
	elmt->next = 0;
	elmt->content = content;
	return (elmt);
}
