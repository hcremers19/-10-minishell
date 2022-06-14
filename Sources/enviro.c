/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:07:15 by hcremers          #+#    #+#             */
/*   Updated: 2022/05/06 11:14:47 by hcremers         ###   ########.fr       */
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
	ret = (char *)malloc(sizeof(char) * (len - s + 1));
	if (!ret)
		return (0);
	r = 0;
	while (s++ < len - 1)
		ret[r++] = str[s];
	ret[r] = 0;
	return (ret);
}

t_env	*create_env(char **env)
{
	int		i;
	t_env	*env_list;

	i = 0;
	env_list = ft_env_lstnew(keep_strt(env[i]), keep_end(env[i]));
	if (!env_list)
		return (NULL);
	i++;
	while (env[i])
	{
		if (!keep_strt(env[i]) || !keep_end(env[i]))
			return (NULL);
		ft_env_lstadd_back(&env_list, \
		ft_env_lstnew(keep_strt(env[i]), keep_end(env[i])));
		i++;
	}
	ft_env_lstadd_back(&env_list, ft_env_lstnew(NULL, NULL));
	return (env_list);
}
