/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:07:15 by hcremers          #+#    #+#             */
/*   Updated: 2022/07/05 20:26:19 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

/*	--------------------------------------------------------------------------
**	Returns whatever is found before the first '=' sign in the string recieved
**	The string returned will be used as the name of the environment variable
**	-----------------------------------------------------------------------	*/

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

/*	--------------------------------------------------------------------------
**	Returns whatever is found after the first '=' sign in the string recieved
**	The string returned will be used as the content of the environment
**	variable
**	-----------------------------------------------------------------------	*/

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

/*	--------------------------------------------------------------------------
**	Uses the 'envp' argument from main to generate the minishell environment
**	-----------------------------------------------------------------------	*/

int	create_env(char **env)
{
	int		i;
	char	*strt;
	char	*end;

	i = 0;
	strt = keep_strt(env[i]);
	end = keep_end(env[i]);
	if (!strt || !end)
		return (ft_free_two(strt, end));
	g_d.env_list = ft_env_lstnew(strt, end);
	if (!g_d.env_list)
		return (-19);
	while (env[++i])
	{
		strt = keep_strt(env[i]);
		end = keep_end(env[i]);
		if (!strt || !end)
			return (ft_free_two(strt, end));
		ft_env_lstadd_back(&g_d.env_list, ft_env_lstnew(strt, end));
	}
	return (0);
}
