/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:02:40 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/23 18:06:14 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*saved;
	static int		i;
	int				n;

	i = 0;
	saved = malloc(ft_alsp(fd, 0));
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
