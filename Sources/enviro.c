/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:07:15 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/04 17:04:36 by hcremers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*keep_strt(char *str)
{
	int		s;
	char	*ret;
	int		r;

	s = 0;
	while (str[s] != '=')
		s++;
	s--;
	ret = (char *)malloc(sizeof(char) * (s + 1));
	if (!ret)
		return (0);
	r = -1;
	while (r++ < s)
		ret[r] = str[r];
	ret[r] = 0;
	return (ret);
}

char	*keep_end(char *str)
{
	int		len;
	int		s;
	char	*ret;
	int		r;

	len = ft_strlen(str);
	s = 0;
	while (str[s] != '=')
		s++;
	ret = (char *)malloc(sizeof(char) * (len - s));
	if (!ret)
		return (0);
	r = 0;
	while (s++ < len - 1)
		ret[r++] = str[s];
	ret[r] = 0;
	return (ret);
}

t_list	*get_env(char **env)
{
	int		i;
	t_list	*env_list;

	i = 0;
	env_list = ft_lstnew(keep_strt(env[i]), keep_end(env[i]));
	i++;
	while (env[i])
	{
		ft_lstadd_back(&env_list, ft_lstnew(keep_strt(env[i]), keep_end(env[i])));
		i++;
	}
	ft_lstadd_back(&env_list, ft_lstnew(NULL, NULL));
	return (env_list);
}
