/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:20:44 by adidion           #+#    #+#             */
/*   Updated: 2021/02/23 15:20:53 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_static(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!str)
		exit(1);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*ft_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		exit(1);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_protect(char *s, char *buff)
{
	if (s)
		free(s);
	if (buff)
		free(buff);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s;
	char		*buff;
	int			i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > OPEN_MAX || 1 > BUFFER_SIZE || line == 0
		|| BUFFER_SIZE >= INT_MAX || !buff)
		exit(1);
	while (!ft_newline(s) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (ft_protect(buff, s));
		buff[i] = '\0';
		s = ft_strjoin(s, buff);
		if (!s)
			return (ft_protect(buff, s));
	}
	free(buff);
	*line = ft_line(s);
	s = ft_static(s);
	return (ft_return(i, s));
}
