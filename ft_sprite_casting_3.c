/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_casting_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:19:20 by adidion           #+#    #+#             */
/*   Updated: 2021/05/04 16:19:23 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	*ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	swap;

	a = 0;
	b = size - 1;
	while (a < (size / 2))
	{
		swap = tab[a];
		tab[a] = tab[b];
		tab[b] = swap;
		a++;
		b--;
	}
	return (tab);
}

int	*ft_sort_sprites(int *tab, double *distance, int size)
{
	int		i;
	int		j;
	int		k;
	double	l;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (fabs(distance[i]) > fabs(distance[i + 1]))
			{
				k = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = k;
				l = distance[i];
				distance[i] = distance[i + 1];
				distance[i + 1] = l;
			}
		}
	}
	ft_rev_int_tab(tab, size);
	return (tab);
}

t_rcst	ft_sprite_casting_2(t_rcst ray_info,
	int i, int *sprite_order, t_obj *sprite)
{
	ray_info.sprite_x = sprite[sprite_order[i]].x
		- ray_info.pos_x;
	ray_info.sprite_y = sprite[sprite_order[i]].y
		- ray_info.pos_y;
	ray_info.inv_det = 1.0 / (ray_info.plan_x * ray_info.dir_y
			- ray_info.dir_x * ray_info.plan_y);
	ray_info.transform_x = ray_info.inv_det * (ray_info.dir_y
			* ray_info.sprite_x - ray_info.dir_x * ray_info.sprite_y);
	ray_info.transform_y = ray_info.inv_det * (-ray_info.plan_y
			* ray_info.sprite_x + ray_info.plan_x * ray_info.sprite_y);
	ray_info.sprite_screen_x = (int)((ray_info.start.ll / 2)
			* (1 + ray_info.transform_x / ray_info.transform_y));
	ray_info.sprite_height = abs((int)(ray_info.start.l
				/ (ray_info.transform_y)));
	ray_info.draw_start_y = -ray_info.sprite_height
		/ 2 + ray_info.start.l / 2;
	return (ray_info);
}
