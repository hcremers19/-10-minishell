#include "../Includes/minishell.h"

// void	parent_process(char **tab, char **envpp, int *fd)
// {
// 	int	fileout;

// 	fileout = open(tab[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fileout == -1)
// 		perror(strerror(2));
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(fileout, STDOUT_FILENO);
// 	close(fd[1]);
// 	ft_exec(tab[3], envpp);
// }

// void	child_process(char **tab, char **envpp, int *fd)
// {
// 	int	filein;

// 	filein = open(tab[1], O_RDONLY, 0777);
// 	dup2(fd[1], STDOUT_FILENO);
// 	dup2(filein, STDIN_FILENO);
// 	close(fd[0]);
// 	ft_exec(tab[2], envpp);
// }

// int open_file(char *tab, int i)
// {
// 	int file;

// 	file = 0;
// 	if (i == 0)
// 	{
// 		file = open(tab, O_WRONLY | O_CREAT | O_APPEND, 0777);
// 		if (!file)
// 			return (0);
// 	}
// 	else if (i == 1)
// 	{
// 		file = open(tab, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 		if (!file)
// 			return (0);
// 	}
// 	else if (i == 2)
// 	{
// 		file = open(tab, O_RDONLY, 0777);
// 		if (!file)
// 			return (0);
// 	}
// 	else if (i == -1)
// 		perror("open");
// 	return (file);
// }

// void	child_process(char *tab, char **envpp)
// {
// 	pid_t pid;
// 	int fd[2];

// 	if (pipe(fd) == -1)
// 		perror("pipe");
// 	pid = fork();
// 	if (pid == -1)
// 		perror("fork");
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		ft_exec(tab, envpp);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		waitpid(pid, NULL, 0);
// 	}
// }

// void	here_doc(char *limiter, int nb)
// {
// 	pid_t reader;
// 	int fd[2];
// 	char *line;

// 	if (nb < 6)
// 		usage();
// 	if (pipe(fd) == -1)
// 		perror("Wrong pipe");
// 	reader = fork();
// 	if (reader == 0)
// 	{
// 		close(fd[0]);
// 		while (get_next_line(&line))
// 		{
// 			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
// 				exit(EXIT_SUCCESS);
// 			write(fd[1], line, ft_strlen(line));
// 		}
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		dup2(fd[0],STDIN_FILENO);
// 		wait(NULL);
// 	}
// }

// int ft_pipe(char **tab, t_data *d, char **envpp)
// {
// 	int i;
// 	int filein;
// 	int fileout;

// 	if (strncmp(tab[1], "here_doc", 8) == 0)
// 	{
// 		i = 3;
// 		fileout = open_file(tab[d->all->nb_cmd - 1], 0);
// 		if (!fileout)
// 			return (-19);
// 		here_doc(tab[2], d->all->nb_cmd);
// 	}
// 	else
// 	{
// 		i = 2;
// 		fileout = open_file(tab[d->all->nb_cmd - 1], 1);
// 		if (!fileout)
// 			return (-19);
// 		filein = open_file(tab[1], 2);
// 		if (!filein)
// 			return (-19);
// 		dup2(filein, STDIN_FILENO);
// 	}
// 	while (i < d->all->nb_cmd - 2)
// 		child_process(tab[i++], envpp);
// 	dup2(fileout, STDOUT_FILENO);
// 	ft_exec(tab[d->all->nb_cmd - 2], envpp);
// 	// usage();
// 	printf("C'est ici\n");
// 	return (0);
// }
