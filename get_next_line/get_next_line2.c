#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		r, i = 0;
	char	*res = malloc(100000);
	char	c;

	if (fd < 0 || !(r = read(fd, &c, 1)))
	{
		free(res);
		return(NULL);
	}
	res[i++] = c;
	while ((r = read(fd, &c, 1) > 0) && c)
		res[i++] = c;
	return (res);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s ", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}