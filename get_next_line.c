/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:02:40 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/25 14:43:04 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	if (!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	while (!ft_checkbuff(buffer, &line))
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	ft_cleanbuff(buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
*/