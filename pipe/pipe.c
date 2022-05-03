#include "pipex.h"

// void	parent_process(char **argv, char **envp, int *fd)
// {
// 	int	fileout;

// 	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fileout == -1)
// 		perror(strerror(2));
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(fileout, STDOUT_FILENO);
// 	close(fd[1]);
// 	ft_exec(argv[3], envp);
// }

// void	child_process(char **argv, char **envp, int *fd)
// {
// 	int	filein;

// 	filein = open(argv[1], O_RDONLY, 0777);
// 	dup2(fd[1], STDOUT_FILENO);
// 	dup2(filein, STDIN_FILENO);
// 	close(fd[0]);
// 	ft_exec(argv[2], envp);
// }

int open_file(char  *argv, int i)
{
	int file;

	file = 0;
	if (i == 0)
		file = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv[1], O_WRONLY | O_RDONLY, 0777);
	else if (i == -1)
		perror("open");
	return (file);
}
void	child_process(char *argv, char **envp)
{
	pid_t pid;
	int fd[2];

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t reader;
	int fd[2];
	char *line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		perror("Wrong pipe");
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(fd))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		wait(NULL);
	}
}
// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];
// 	pid_t	id;

// 	if (argc < 5)
// 		perror(strerror(130));
// 	if (argc > 5)
// 		perror(strerror(7));
// 	if (argc == 5)
// 	{
// 		if (pipe(fd) < 0 || !argv)
// 		{
// 			perror(strerror(32));
// 			exit(EXIT_FAILURE);
// 		}
// 		id = fork();
// 		if (id < 0)
// 			perror(strerror(10));
// 		if (id == 0)
// 			child_process(argv, envp, fd);
// 		waitpid(id, NULL, 0);
// 		parent_process(argv, envp, fd);
// 		close(fd[0]);
// 		close(fd[1]);
// 	}
// 	return (0);
// }

int main(int argc, char **argv, char **envp)
{
	int i;
	int filein;
	int fileout;

	if (argc >= 5)
	{
		if (strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		ft_exec(argv[argc - 2], envp);
	}
	usage();
}