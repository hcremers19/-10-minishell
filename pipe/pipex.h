/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 04:26:53 by agoloube          #+#    #+#             */
/*   Updated: 2022/01/06 14:48:41 by agoloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/stat.h>

char	*get_cmd_path(char *cmd, char **envp);
void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char *argv, char **envp);
void	ft_exec(char *argv, char **envp);
void usage(void);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int get_next_line(char **line);
size_t	ft_strlen(const char *str);  
void	ft_putstr_fd(char *str, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
