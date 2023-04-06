#include "get_next_line.h"

int main(void)
{
    char    *line;
    int     fd;

    fd = open("prueba.txt", O_RDONLY);

    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s\n", line);
        free (line);
    }
}