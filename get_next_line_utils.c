/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:20:58 by adidion           #+#    #+#             */
/*   Updated: 2021/02/23 15:21:00 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free((char *)s1);
	return (str);
}

int	ft_return(int i, char *s)
{
	if (i == 0)
	{
		if (s)
			free(s);
		return (0);
	}
	else
		return (1);
}

char	*get_next_line_2(int fd, char **line)
{
	static char	*s;
	char		*buff;
	int			i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > OPEN_MAX || 1 > BUFFER_SIZE || line == 0
		|| BUFFER_SIZE >= INT_MAX || !buff)
		return (ft_protect_2(buff, s));
	while (!ft_newline(s) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (ft_protect_2(buff, s));
		buff[i] = '\0';
		s = ft_strjoin(s, buff);
		if (!s)
			return (ft_protect_2(buff, s));
	}
	free(buff);
	*line = ft_line(s);
	s = ft_static(s);
	return (*line);
}
