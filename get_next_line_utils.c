/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 08:08:49 by plopes-c          #+#    #+#             */
/*   Updated: 2022/11/23 18:05:37 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_alsp(int fd, size_t i)
{
	char	*str;

	if (str[i] != '\n')
	{
		str = malloc(BUFFER_SIZE);
		read(fd, str, BUFFER_SIZE);
		while (str[i] && str[i] != '\n')
			i++;
		i = ft_alsp(fd, i);
		free(str);
	}
	else
		return (i);
}

/*
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		n;
	int		i;

	n = 0;
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
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
*/