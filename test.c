
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(char *s);
int		snl(char	*str);
char	*ft_strjoin(size_t i, char *s2);
char	*get_next_line(int fd);

int	snl(char	*str)
{
	int	i;

	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	if (!str[i])
		return (1);
	return (0);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	static char	*str;
	int			n;
	int			i;

	n = 0;
	str = malloc(i + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s2[n] && s2[n] != '\n')
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	if (s2[n] == '\n')
		str[i] = '\n';
	return (str);
}

char	*get_next_line(int fd)
{
	char				*buffer;
	static char			*saved;
	int					i;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	saved = ft_strjoin(ft_strlen(saved), buffer);
	free (buffer);
	while (saved[i] != '\n' && saved[i])
	{
		buffer = malloc(BUFFER_SIZE);
		read(fd, buffer, BUFFER_SIZE);
		saved = ft_strjoin(ft_strlen(saved), buffer);
		free (buffer);
		i++;
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
