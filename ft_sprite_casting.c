/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:19:00 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 17:19:02 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#define U_DIV 1
#define V_DIV 1
#define V_MOVE 0.0

//void	ft_sort_sprites(int *order, double *dist, int amount)
//{
//	int i;
//
//	i = -1;
//}
//
int	*ft_rev_int_tab(int *tab, int size)
{
	int a;
	int b;
	int swap;

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

int *ft_sort_sprites(int *tab, double *distance, int size)
{
	int i;
	int j;
	int k;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (distance[i] > distance[i + 1])
			{
				k = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = k;
			}
			i++;
		}
		j++;
	}
	ft_rev_int_tab(tab, size);
	return (tab);
} // retourner le tab

t_rcst	ft_sprite_casting(t_rcst ray_info, double *z_buffer)
{
	int i;
	int stripe;
	int y;
	int d;
	double *sprite_distance;
	int *sprite_order;
	t_obj *sprite;

	sprite = malloc(sizeof(t_obj) * ray_info.sprite_num);
	sprite = ft_get_sprite_pos(sprite, ray_info);
	i = -1;
	sprite_order = malloc(sizeof(int) * ray_info.sprite_num);
	sprite_distance = malloc(sizeof(double) * ray_info.sprite_num);
	while (++i < ray_info.sprite_num)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((ray_info.pos_x - sprite[i].x) * (ray_info.pos_x
				- sprite[i].x) + (ray_info.pos_y - ray_info.sprite[i].y) *
				(ray_info.pos_y - sprite[i].y));
	}
	sprite_order = ft_sort_sprites(sprite_order, sprite_distance, ray_info.sprite_num);
	i = -1;
	while (++i < ray_info.sprite_num)
	{
		ray_info.sprite_x = sprite[sprite_order[i]].x - ray_info.pos_x;
		ray_info.sprite_y = sprite[sprite_order[i]].y - ray_info.pos_y;
		if ((ray_info.plan_x * ray_info.dir_y - ray_info.dir_x * ray_info.plan_y) != 0)
		ray_info.inv_det = 1.0 / (ray_info.plan_x * ray_info.dir_y - ray_info.dir_x * ray_info.plan_y);
		else
		ray_info.inv_det = 0;
		ray_info.transform_x = ray_info.inv_det * (ray_info.dir_y * ray_info.sprite_x - ray_info.dir_x * ray_info.sprite_y);
		ray_info.transform_y = ray_info.inv_det * (-ray_info.plan_y * ray_info.sprite_x + ray_info.plan_x * ray_info.sprite_y);
		if (ray_info.transform_y != 0)
		ray_info.sprite_screen_x = (int)((ray_info.start.ll / 2) * (1 + ray_info.transform_x / ray_info.transform_y));
		else
		ray_info.sprite_screen_x = 0;
		//ray_info.v_move_screen = (int)(V_MOVE / ray_info.transform_y);
		if (ray_info.transform_y != 0)
		ray_info.sprite_height = abs((int)(ray_info.start.l / (ray_info.transform_y)));// / V_DIV;
		else
			ray_info.sprite_height = 0;
		ray_info.draw_start_y = -ray_info.sprite_height / 2 + ray_info.start.l / 2;// + ray_info.v_move_screen;
		if (ray_info.draw_start_y < 0)
			ray_info.draw_start_y = 0;
		ray_info.draw_end_y = ray_info.sprite_height / 2 + ray_info.start.l / 2;// + ray_info.v_move_screen;
		if (ray_info.draw_end_y >= ray_info.start.l)
			ray_info.draw_end_y = ray_info.start.l - 1;
		if (ray_info.transform_y != 0)
		ray_info.sprite_width = abs((int)(ray_info.start.l / (ray_info.transform_y)));// / U_DIV;
		else
			ray_info.sprite_width = 0;
		ray_info.draw_start_x = -ray_info.sprite_width / 2 + ray_info.sprite_screen_x;
		if (ray_info.draw_start_x < 0)
			ray_info.draw_start_x = 0;
		ray_info.draw_end_x = ray_info.sprite_width / 2 + ray_info.sprite_screen_x;
		if (ray_info.draw_end_x >= ray_info.start.ll)
			ray_info.draw_end_x = ray_info.start.ll - 1;
		stripe = ray_info.draw_start_x - 1;
		while (++stripe < ray_info.draw_end_x)
		{
			if (ray_info.sprite_width != 0)
			ray_info.tex_x_2 = (int)(256 * (stripe - (-ray_info.sprite_width / 2 + ray_info.sprite_screen_x)) * 64 / ray_info.sprite_width) / 256;
			else
				ray_info.tex_x_2 = 0;
			if (ray_info.transform_y > 0 && stripe > 0 && stripe < ray_info.start.ll && ray_info.transform_y < z_buffer[stripe])
			{
				y = ray_info.draw_start_y - 1;
				while (++y < ray_info.draw_end_y)
				{
					d = (y) * 256 - ray_info.start.l * 128 + ray_info.sprite_height * 128;
					if (ray_info.sprite_height != 0)
					ray_info.tex_y_2 = ((d * 64) / ray_info.sprite_height) / 256;
					else
						ray_info.tex_y_2 = 0;
					ray_info.color = my_mlx_pixel_get(&ray_info.xpm_sprite,
					ray_info.tex_x_2, ray_info.tex_y_2);
					if (ray_info.color != 0)
					{
						my_mlx_pixel_put(&ray_info.data, stripe, y, ray_info.color);
					}
				}
			}
		}
	}
	free(sprite_order);
	free(sprite);
	return (ray_info);
}
