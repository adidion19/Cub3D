/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcst_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:02:00 by adidion           #+#    #+#             */
/*   Updated: 2021/03/16 15:02:02 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rcst	ft_rcst_calculate(t_rcst ray_info, int y)
{
	while (ray_info.hit == 0)
	{
		if (ray_info.side_dest_x < ray_info.side_dest_y)
		{
			ray_info.side_dest_x += ray_info.delta_dist_x;
			ray_info.map_x += ray_info.step_x;
			ray_info.side = 0;
		}
		else
		{
			ray_info.side_dest_y += ray_info.delta_dist_y;
			ray_info.map_y += ray_info.step_y;
			ray_info.side = 1;
		}
		y = ray_info.start.tab[ray_info.map_x][ray_info.map_y];
		if (y != 9 && y != 3 && y != 4 && y != 5 && y != 6 && y != 2)
			ray_info.hit = 1;
	}
	if (ray_info.side == 0)
		ray_info.perp_wall_dist = (ray_info.map_x - ray_info.pos_x
				+ (1 - ray_info.step_x) / 2) / ray_info.ray_dir_x;
	else
		ray_info.perp_wall_dist = (ray_info.map_y - ray_info.pos_y
				+ (1 - ray_info.step_y) / 2) / ray_info.ray_dir_y;
	return (ray_info);
}

t_rcst	ft_rcst_loop(t_mlx window, t_map start, t_rcst ray_info)
{
	int		c;
	double	*z_buffer;

	c = -1;
	z_buffer = malloc(sizeof(double) * ray_info.start.ll);
	if (!z_buffer)
		exit(1);
	while (++c < start.ll)
	{
		ray_info.cam_x = 2 * c / (double)(start.ll) - 1;
		ray_info.ray_dir_x = ray_info.dir_x + ray_info.plan_x * ray_info.cam_x;
		ray_info.ray_dir_y = ray_info.dir_y + ray_info.plan_y * ray_info.cam_x;
		ray_info = ft_rcst_fill_3(ray_info);
		ray_info = ft_rcst_fill_4(ray_info);
		ray_info = ft_rcst_calculate(ray_info, 0);
		ray_info = ft_rcst_calculate_2(start, ray_info);
		ray_info = ft_rcst_calculate_3(start, ray_info);
		ray_info = ft_rcst_calculate_4(ray_info, c, ray_info.draw_start - 1);
		z_buffer[c] = ray_info.perp_wall_dist;
	}
	ray_info = ft_sprite_casting(ray_info, z_buffer);
	ft_push_image_to_window(ray_info, window);
	free(z_buffer);
	return (ray_info);
}

t_rcst	ft_rcst_fill_2(t_mlx window, t_map start, t_rcst ray_info)
{
	ray_info.cam_time = 0;
	ray_info.old_time = 0;
	ray_info.xpm_n = ft_xpm_to_image_n(ray_info);
	ray_info.xpm_s = ft_xpm_to_image_s(ray_info);
	ray_info.xpm_e = ft_xpm_to_image_e(ray_info);
	ray_info.xpm_w = ft_xpm_to_image_w(ray_info);
	ray_info.xpm_sprite = ft_xpm_to_image_sprite(ray_info);
	ray_info = ft_rcst_loop(window, start, ray_info);
	return (ray_info);
}

t_rcst	ft_rcst_fill_1(t_mlx window, t_map start, t_rcst ray_info)
{
	if (start.start == 3)
	{
		ray_info.dir_x = -ray_info.plan_y;
		ray_info.plan_y = ray_info.plan_y;
	}
	else if (start.start == 5)
	{
		ray_info.dir_x = ray_info.plan_y;
		ray_info.plan_y = -ray_info.plan_y;
	}
	else if (start.start == 4)
	{
		ray_info.dir_y = ray_info.plan_y;
		ray_info.plan_x = M_PI / 4;
		ray_info.plan_y = 0;
	}
	else
	{
		ray_info.dir_y = -ray_info.plan_y;
		ray_info.plan_x = -M_PI / 4;
		ray_info.plan_y = 0;
	}
	ray_info = ft_rcst_fill_2(window, start, ray_info);
	return (ray_info);
}

t_rcst	ft_rcst_fill(t_mlx window, t_map start, t_rcst ray_info)
{
	ray_info.sprite_num = ft_num_sprite(ray_info.start.tab);
	ray_info.pos_x = start.x + 0.5;
	ray_info.pos_y = start.y + 0.5;
	ray_info.plan_x = 0;
	ray_info.plan_y = 0;
	ray_info.dir_x = 0;
	ray_info.dir_y = 0;
	ray_info.plan_y = M_PI / 4;
	ray_info = ft_rcst_fill_1(window, start, ray_info);
	return (ray_info);
}
