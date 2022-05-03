#include "pipex.h"

int get_next_line(char **line)
{
    char *buffer;
    int i;
    int r;
    int c;

    i = 0;
    r = 0;
    buffer = (char *)malloc(10000);
    if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void usage(void)
{
	ft_putstr_fd("Error: Bad argument", 2);
	exit(EXIT_SUCCESS);
}