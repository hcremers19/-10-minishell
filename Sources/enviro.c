/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:07:15 by hcremers          #+#    #+#             */
/*   Updated: 2022/06/15 10:44:07 by hcremers         ###   ########.fr       */
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

int create_env(char **env)
{
	int		i;

	i = 0;
	d.env_list = ft_env_lstnew(keep_strt(env[i]), keep_end(env[i]));
	if (!d.env_list)
		return (1);
	i++;
	while (env[i])
	{
		if (!keep_strt(env[i]) || !keep_end(env[i]))
			return (1);
		ft_env_lstadd_back(&d.env_list,
			ft_env_lstnew(keep_strt(env[i]), keep_end(env[i])));
		i++;
	}
	ft_env_lstadd_back(&d.env_list, ft_env_lstnew(NULL, NULL));
	return (0);
}
// Il semble manquer une ligne à l'environnement, vérifier si ça vient de la récupération de l'environnement ou juste de son impression