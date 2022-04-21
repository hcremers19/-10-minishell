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
void	child_process(char **argv, char **envp, int *fd);
void	ft_exec(char *argv, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

#endif