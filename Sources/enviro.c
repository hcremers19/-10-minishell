/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:07:15 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/28 11:55:32 by hcremers         ###   ########.fr       */
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

int	create_env(char **env)
{
	int		i;
	char	*strt;
	char	*end;

	i = 0;
	strt = keep_strt(env[i]);
	end = keep_end(env[i]);
	g_d.env_list = ft_env_lstnew(strt, end);
	if (!g_d.env_list)
		return (1);
	// free(strt);
	// free(end);
	i++;
	while (env[i])
	{
		strt = keep_strt(env[i]);
		end = keep_end(env[i]);
		if (!strt || !end)
			return (1);
		ft_env_lstadd_back(&g_d.env_list, ft_env_lstnew(strt, end));
		// free(strt);
		// free(end);
		i++;
	}
	// ft_env_lstadd_back(&g_d.env_list, ft_env_lstnew(NULL, NULL));
	return (0);
}
