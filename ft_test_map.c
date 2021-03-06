/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:40:22 by adidion           #+#    #+#             */
/*   Updated: 2021/03/08 12:19:43 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_intlen(int *a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

int	ft_big_if(int **tab, int x_max, int i, int j)
{
	if (i == 0 || j == 0 || j == x_max - 1
		|| tab[i][j + 1] == 7 || tab[i][j - 1] == 7
		|| tab[i + 1][j] == 7 || tab[i - 1][j] == 7
		|| tab[i + 1][j - 1] == 7 || tab[i + 1][j + 1] == 7
		|| tab[i - 1][j - 1] == 7 || tab[i - 1][j + 1] == 7
		|| !tab[i][j - 1]
		|| !tab[i + 1][j] || !tab[i - 1][j]
		|| !tab[i + 1][j - 1]
		|| !tab[i - 1][j - 1])
		return (0);
	return (1);
}

int	ft_test_map(int **tab)
{
	int	i;
	int	j;
	int	y_max;
	int	x_max;

	i = -1;
	y_max = -1;
	while (tab[++y_max])
		;
	while (tab[++i])
	{
		x_max = ft_intlen(tab[i]);
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 9 || tab[i][j] == 3 || tab[i][j] == 4 || tab[i][j] == 5
				|| tab[i][j] == 6)
			{
				if (!ft_big_if(tab, x_max, i, j) || i == y_max)
					printf("Error\nInvalid map\n");
				if (!ft_big_if(tab, x_max, i, j) || i == y_max)
					exit(1);
			}
		}
	}
	return (1);
}

int	ft_test_ext(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '.' && str[i])
		;
	if (str[++i] == 'c')
		if (str[++i] == 'u')
			if (str[++i] == 'b')
				if (!str[i + 1])
					return (1);
	return (0);
}
