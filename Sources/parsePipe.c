#include "../Includes/minishell.h"

int parsePipe(t_one arg, char **strpiped)
{
    int i;

    i = 0;
    while (i < 2)
    {
    strpiped[i] = ft_split(arg.all_cmd, "|");
    if (strpiped[i] == NULL)
        break ;
    }
    if (strpiped[1] == NULL)
        return (0);
    else 
        return (1);
}
