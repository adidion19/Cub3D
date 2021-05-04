/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcst_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:09:12 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 14:09:15 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rcst	ft_rcst_calculate_2(t_map start, t_rcst ray_info)
{
	ray_info.line_hight = (int)(start.l / ray_info.perp_wall_dist);
	ray_info.draw_start = -ray_info.line_hight / 2 + start.l / 2;
	if (ray_info.draw_start < 0)
		ray_info.draw_start = 0;
	ray_info.draw_end = ray_info.line_hight / 2 + start.l / 2;
	if (ray_info.draw_end >= start.l)
		ray_info.draw_end = start.l - 1;
	return (ray_info);
}

void	ft_draw_floor_and_cell(t_rcst ray_info, int x)
{
	int		i;
	int		y;
	char	str[4];
	int		j;

	y = -1;
	str[3] = 0;
	str[2] = ray_info.start.cell_r;
	str[1] = ray_info.start.cell_g;
	str[0] = ray_info.start.cell_b;
	j = ft_char_to_int(str);
	i = ray_info.start.l / 2;
	while (++y < i)
		my_mlx_pixel_put(&ray_info.data, x, y, j);
	str[2] = ray_info.start.floor_r;
	str[1] = ray_info.start.floor_g;
	str[0] = ray_info.start.floor_b;
	j = ft_char_to_int(str);
	while (++y < ray_info.start.l - 1)
		my_mlx_pixel_put(&ray_info.data, x, y, j);
}

t_data	ft_data_fill(t_data img)
{
	img.img = 0;
	img.addr = 0;
	img.bits_per_pixel = 0;
	img.line_length = 0;
	img.endian = 0;
	return (img);
}

t_rcst	ft_rcst_calculate_3(t_map start, t_rcst ray_info)
{
	ray_info.tex_num = start.tab[ray_info.map_x][ray_info.map_y] - 1;
	if (ray_info.side == 0)
		ray_info.wall_x = ray_info.pos_y + ray_info.perp_wall_dist
			* ray_info.ray_dir_y;
	else
		ray_info.wall_x = ray_info.pos_x + ray_info.perp_wall_dist
			* ray_info.ray_dir_x;
	ray_info.wall_x -= floor(ray_info.wall_x);
	ray_info.tex_x = (int)(ray_info.wall_x * (double)64);
	if (ray_info.side == 0 && ray_info.ray_dir_x > 0)
		ray_info.tex_x = 64 - ray_info.tex_x - 1;
	if (ray_info.side == 1 && ray_info.ray_dir_y < 0)
		ray_info.tex_x = 64 - ray_info.tex_x - 1;
	return (ray_info);
}

t_rcst	ft_rcst_calculate_4(t_rcst ray_info, int x, int y)
{
	ft_draw_floor_and_cell(ray_info, x);
	ray_info.step = 1.0 * 64 / ray_info.line_hight;
	ray_info.tex_pos = (ray_info.draw_start - ray_info.start.l / 2
			+ ray_info.line_hight / 2) * ray_info.step;
	y = ray_info.draw_start - 1;
	while (++y < ray_info.draw_end)
	{
		ray_info.tex_y = (int)ray_info.tex_pos & (64 - 1);
		ray_info.tex_pos += ray_info.step;
		if (ray_info.map_x - ray_info.pos_x <= 0 && ray_info.side == 0)
			ray_info.color = my_mlx_pixel_get(&ray_info.xpm_n,
					ray_info.tex_x, ray_info.tex_y);
		else if (ray_info.map_x - ray_info.pos_x > 0 && ray_info.side == 0)
			ray_info.color = my_mlx_pixel_get(&ray_info.xpm_s,
					ray_info.tex_x, ray_info.tex_y);
		else if (ray_info.map_y - ray_info.pos_y > 0 && ray_info.side == 1)
			ray_info.color = my_mlx_pixel_get(&ray_info.xpm_e,
					ray_info.tex_x, ray_info.tex_y);
		else
			ray_info.color = my_mlx_pixel_get(&ray_info.xpm_w,
					ray_info.tex_x, ray_info.tex_y);
		my_mlx_pixel_put(&ray_info.data, x - 1, y, ray_info.color);
	}
	return (ray_info);
}
