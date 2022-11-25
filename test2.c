#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_alsp(int fd, char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\n' && str[i])
	{
		str = malloc(BUFFER_SIZE);
		read(fd, str, BUFFER_SIZE);
		while (str[i] && str[i] != '\n')
			i++;
		i = ft_alsp(fd, str);
		free(str);
	}
	else
		return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*saved;
	static int		i;
	int				n;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	saved = malloc(ft_alsp(fd, buffer));
	free(buffer);
	while (saved[i] != '\n')
	{
		buffer = malloc(BUFFER_SIZE);
		read(fd, buffer, BUFFER_SIZE);
		n = 0;
		while (buffer[i])
		{
			saved[i] = buffer[n];
			i++;
			n++;
		}
		free(buffer);
	}
	return (saved);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}