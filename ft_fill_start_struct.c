/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_start_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:15:36 by adidion           #+#    #+#             */
/*   Updated: 2021/03/08 12:05:24 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_print_and_exit(void)
{
	printf("Error\nTwo player's starts\n");
	exit(1);
}

char	*ft_strjoin_2(char *s1, char *s2)
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
		exit(1);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

t_map	ft_fill_start_struct(int **tab, int a)
{
	int		i;
	int		j;
	t_map	start;
	int		bool;

	bool = 0;
	start.tab = tab;
	i = -1;
	while (tab[++i] && a--)
	{
		j = -1;
		while (tab[i][++j])
		{
			if ((tab[i][j] >= 3 && tab[i][j] <= 6) || tab[i][j] == 5)
			{
				if (bool == 1)
					ft_print_and_exit();
				start.start = tab[i][j];
				start.x = i;
				start.y = j;
				bool = 1;
			}
		}
	}
	return (start);
}
