#include "../Includes/pipe.h"

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		perror(strerror(2));
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_exec(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	ft_exec(argv[2], envp);
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
