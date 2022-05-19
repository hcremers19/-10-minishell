#include "../Includes/minishell.h"

int execpipe(int argc, char *argv, char *envp)
{
    t_one cmd;

    if (get_type(cmd.type) == 0)
    {
        ft_pipe(argc, argv, envp);
    }
}
