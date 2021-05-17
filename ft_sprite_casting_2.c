/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_casting_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:34:32 by adidion           #+#    #+#             */
/*   Updated: 2021/05/04 12:34:35 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_num_sprite(int **tab)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	if (!tab)
		return (EXIT_FAILURE);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (tab[i][j] == 2)
				count++;
	}
	return (count);
}

t_obj	*ft_get_sprite_pos(t_obj *sprite, t_rcst ray_info)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (ray_info.start.tab[++i])
	{
		j = -1;
		while (ray_info.start.tab[i][++j])
		{
			if (ray_info.start.tab[i][j] == 2)
			{
				k++;
				sprite[k].x = i + 0.5;
				sprite[k].y = j + 0.5;
			}
		}
	}
	return (sprite);
}

t_obj	*malloc_sprite(t_rcst ray_info)
{
	t_obj	*sprite;

	sprite = malloc(sizeof(t_obj) * ray_info.sprite_num);
	if (!sprite)
		exit(1);
	return (sprite);
}

int	*malloc_sprite_order(t_rcst ray_info)
{
	int	*sprite_order;

	sprite_order = malloc(sizeof(int) * ray_info.sprite_num);
	if (!sprite_order)
		exit(1);
	return (sprite_order);
}

double	*malloc_sprite_distance(t_rcst ray_info)
{
	double	*sprite_distance;

	sprite_distance = malloc(sizeof(double) * ray_info.sprite_num);
	if (!sprite_distance)
		exit(1);
	return (sprite_distance);
}
