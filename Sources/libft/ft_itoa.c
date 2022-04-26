/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:56:08 by hcremers          #+#    #+#             */
/*   Updated: 2021/10/08 14:56:10 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_putzero(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

static char	*ft_positoa(long int n, int i)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!p)
		return (0);
	i = ft_intlen(n);
	p[i] = 0;
	i--;
	while (i >= 0)
	{
		p[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (p);
}

static char	*ft_negitoa(long int n, int i)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_intlen(n) + 2));
	if (!p)
		return (0);
	i = ft_intlen(n) + 1;
	n = -n;
	p[i] = 0;
	i--;
	while (i >= 1)
	{
		p[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	p[i] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;

	i = 0;
	nb = n;
	if (nb == 0)
		return (ft_putzero());
	else if (nb > 0)
		return (ft_positoa(nb, i));
	else if (nb < 0)
		return (ft_negitoa(nb, i));
	return (0);
}
