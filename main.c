#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int    main(int ac, char **av)
{
    int    fd;
    char    *line;

    line = NULL;
    (void)ac;
    (void)av;
    //if ((fd = open(av[1], O_RDONLY)) < 0)
    //    return (1);
    if ((fd = open("42TESTERS-GNL/files/mix_marge2", O_RDONLY)) < 0)
        return (1);
    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
        line = NULL;
    }
    printf("%s\n", line);
    free(line);
    line = NULL;
    close(fd);
    return (0);
}