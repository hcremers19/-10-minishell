/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:19:10 by acaillea          #+#    #+#             */
/*   Updated: 2022/05/19 12:19:14 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_exec(char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(*argv, ' ');
	if (execve(get_cmd_path(cmd[0], envp), cmd, envp) == -1)
	{
		perror(strerror(8));
		exit (127);
	}
}

// char	*get_cmd_path(char *cmd, char **envp)
// {
// 	char		**path_str;
// 	char		*path;
// 	char		*split_path;
// 	int			i;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
// 		i++;
// 	if (!envp[i])
// 		perror(strerror(14));
// 	path_str = ft_split(envp[i] + 5, ':');
// 	i = 0;
// 	while (path_str[i])
// 	{
// 		split_path = ft_strjoin(path_str[i], "/");
// 		path = ft_strjoin(split_path, cmd);
// 		free(split_path);
// 		if (access(path, F_OK) == 0)
// 			return (path);
// 		i++;
// 	}
// 	return (0);
// }

// static int	word_count(char const *s, char c)
// {
// 	size_t	count;
// 	size_t	i;

// 	i = 0;
// 	count = 0;
// 	while (s[i] == c && s[i])
// 		i++;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			count++;
// 		while (s[i] == c && s[i])
// 			i++;
// 		if (s[i] != c && s[i])
// 			i++;
// 	}
// 	if (!s[0])
// 		count = 0;
// 	else if (s[i - 1] != c)
// 		count++;
// 	return (count);
// }

// static char	**free_malloc(char **tab, int count)
// {
// 	while (tab[--count])
// 		free(tab[count]);
// 	free (tab);
// 	return (NULL);
// }

// static char	**ft_word(char *s, char c, char **tab, size_t count)
// {
// 	size_t	str_i;
// 	size_t	word_i;
// 	size_t	y_i;

// 	str_i = 0;
// 	word_i = 0;
// 	y_i = 0;
// 	while (y_i < count)
// 	{
// 		while (s[str_i] == c)
// 			str_i++;
// 		word_i = str_i;
// 		while (s[word_i + 1] != c && s[word_i + 1])
// 			word_i++;
// 		tab[y_i] = ft_substr(s, str_i, word_i - str_i + 1);
// 		if (!tab[y_i])
// 			return (free_malloc(tab, y_i));
// 		str_i = word_i + 1;
// 		y_i++;
// 	}
// 	tab[y_i] = 0;
// 	return (tab);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**tab;
// 	char	**tab2;
// 	char	*new_s;
// 	size_t	count;

// 	new_s = (char *)s;
// 	if (!new_s)
// 		return (NULL);
// 	count = word_count(s, c);
// 	tab = malloc(sizeof(char *) * (count + 1));
// 	if (!tab)
// 		return (NULL);
// 	tab2 = ft_word(new_s, c, tab, count);
// 	return (tab2);
// }
