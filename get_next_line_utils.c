/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:08:49 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/28 18:00:17 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s)
		i += (s[i] == '\n');
	return (i);
}

int	ft_checkbuff(char *str, char **line)
{
	int		i;

	i = 0;
	if (!str[0])
		return (1);
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strjoin(str, (*line));
	if (str[i] == '\n')
	{
		return (1);
	}
	return (0);
}

char	*ft_strjoin(char const *str, char *line)
{
	char	*newstr;
	int		i;
	int		n;

	i = 0;
	n = 0;
	newstr = malloc((ft_strlen(str)) + (ft_strlen(line)) + 1);
	if (!newstr)
		return (NULL);
	while (line && line[i] != '\0')
	{
		newstr[i] = line[i];
		i++;
	}
	while (str && str[n] && (i == 0 || str[n - 1] != '\n'))
		newstr[i++] = str[n++];
	newstr[i] = '\0';
	if (line)
		free(line);
	return (newstr);
}

void	ft_cleanbuff(char *buffer)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	while (i < BUFFER_SIZE)
		buffer[n++] = buffer[i++];
	while (n < BUFFER_SIZE)
		buffer[n++] = 0;
}
