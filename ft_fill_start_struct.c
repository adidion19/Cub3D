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

t_map	ft_fill_start_struct(int **tab, int a)
{
	int		i;
	int		j;
	t_map	start;

	start.tab = tab;
	i = 0;
	j = 0;
	while (tab[i] && a--)
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] >= 3 && tab[i][j] <= 6) || tab[i][j] == 5)
			{
				start.start = tab[i][j];
				start.x = i;
				start.y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (start);
}
