# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char character;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    char *buffer = malloc(100000);
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    buffer[i] = '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL);
    return (buffer);
}

#include<fcntl.h>
# include <stdio.h>

int main(int ac, char **av)
{
    (void)ac;
    char *line = NULL;
    int fd = open(av[1], O_RDONLY);
    while((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    return(0);
}

// gcc -Wall -Werror -Wextra get_next_line1.c -D BUFFER_SIZE=10 && ./a.out get_next_line1.c