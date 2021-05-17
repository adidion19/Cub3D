/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:19:00 by adidion           #+#    #+#             */
/*   Updated: 2021/05/04 12:34:25 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rcst	ft_sprite_casting_3(t_rcst ray_info, int *sprite_order,
	t_obj *sprite, double *sprite_distance)
{
	int	i;

	i = -1;
	while (++i < ray_info.sprite_num)
	{
		sprite_order[i] = i;
		sprite_distance[i] = (fabs(((ray_info.pos_x - sprite[i].x)
						* (ray_info.pos_x - sprite[i].x)))
				+ fabs(((ray_info.pos_y - ray_info.sprite[i].y)
						* (ray_info.pos_y - sprite[i].y))));
	}
	sprite_order = ft_sort_sprites(sprite_order,
			sprite_distance, ray_info.sprite_num);
	return (ray_info);
}

t_rcst	ft_sprite_casting_4(t_rcst ray_info)
{
	if (ray_info.draw_start_y < 0)
		ray_info.draw_start_y = 0;
	ray_info.draw_end_y = ray_info.sprite_height / 2 + ray_info.start.l / 2;
	if (ray_info.draw_end_y >= ray_info.start.l)
		ray_info.draw_end_y = ray_info.start.l - 1;
	ray_info.sprite_width = abs((int)(ray_info.start.l
				/ (ray_info.transform_y)));
	ray_info.draw_start_x = -ray_info.sprite_width
		/ 2 + ray_info.sprite_screen_x;
	if (ray_info.draw_start_x < 0)
		ray_info.draw_start_x = 0;
	ray_info.draw_end_x = ray_info.sprite_width / 2 + ray_info.sprite_screen_x;
	if (ray_info.draw_end_x >= ray_info.start.ll)
		ray_info.draw_end_x = ray_info.start.ll - 1;
	return (ray_info);
}

t_rcst	ft_sprite_casting_6(t_rcst ray_info, int stripe, int y)
{
	int	d;

	d = (y) * 256 - ray_info.start.l
		* 128 + ray_info.sprite_height * 128;
	ray_info.tex_y_2 = ((d * 64) / ray_info.sprite_height) / 256;
	ray_info.color = my_mlx_pixel_get(&ray_info.xpm_sprite,
			ray_info.tex_x_2, ray_info.tex_y_2);
	if ((ray_info.color & 0x00FFFFFF))
		my_mlx_pixel_put(&ray_info.data, stripe, y, ray_info.color);
	return (ray_info);
}

t_rcst	ft_sprite_casting_5(t_rcst ray_info, int stripe, double *z_buffer)
{
	int	y;

	while (++stripe < ray_info.draw_end_x)
	{
		ray_info.tex_x_2 = (int)(256 * (stripe - (-ray_info.sprite_width
						/ 2 + ray_info.sprite_screen_x)) * 64
				/ ray_info.sprite_width) / 256;
		if (ray_info.transform_y > 0 && stripe > 0
			&& stripe < ray_info.start.ll
			&& ray_info.transform_y < z_buffer[stripe])
		{
			y = ray_info.draw_start_y - 1;
			while (++y < ray_info.draw_end_y)
			{
				ray_info = ft_sprite_casting_6(ray_info, stripe, y);
			}
		}
	}
	return (ray_info);
}

t_rcst	ft_sprite_casting(t_rcst ray_info, double *z_buffer)
{
	int		i;
	int		stripe;
	double	*sprite_distance;
	int		*sprite_order;
	t_obj	*sprite;

	sprite = malloc_sprite(ray_info);
	sprite = ft_get_sprite_pos(sprite, ray_info);
	sprite_order = malloc_sprite_order(ray_info);
	sprite_distance = malloc_sprite_distance(ray_info);
	ray_info = ft_sprite_casting_3(ray_info,
			sprite_order, sprite, sprite_distance);
	i = -1;
	while (++i < ray_info.sprite_num)
	{
		ray_info = ft_sprite_casting_2(ray_info, i, sprite_order, sprite);
		ray_info = ft_sprite_casting_4(ray_info);
		stripe = ray_info.draw_start_x - 1;
		ray_info = ft_sprite_casting_5(ray_info, stripe, z_buffer);
	}
	free(sprite_order);
	free(sprite);
	free(sprite_distance);
	return (ray_info);
}
