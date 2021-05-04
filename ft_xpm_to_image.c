/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:04:30 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 14:04:32 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_data	ft_xpm_to_image_n(t_rcst ray_info)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	ray_info.xpm_n.img = mlx_xpm_file_to_image(ray_info.window.mlx,
			ray_info.start.n_texture, &a, &b);
	ray_info.xpm_n.addr = mlx_get_data_addr(ray_info.xpm_n.img,
			&ray_info.xpm_n.bits_per_pixel, &ray_info.xpm_n.line_length,
			&ray_info.xpm_n.endian);
	return (ray_info.xpm_n);
}

t_data	ft_xpm_to_image_s(t_rcst ray_info)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	ray_info.xpm_s.img = mlx_xpm_file_to_image(ray_info.window.mlx,
			ray_info.start.s_texture, &a, &b);
	ray_info.xpm_s.addr = mlx_get_data_addr(ray_info.xpm_s.img,
			&ray_info.xpm_s.bits_per_pixel, &ray_info.xpm_s.line_length,
			&ray_info.xpm_s.endian);
	return (ray_info.xpm_s);
}

t_data	ft_xpm_to_image_e(t_rcst ray_info)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	ray_info.xpm_e.img = mlx_xpm_file_to_image(ray_info.window.mlx,
			ray_info.start.e_texture, &a, &b);
	ray_info.xpm_e.addr = mlx_get_data_addr(ray_info.xpm_e.img,
			&ray_info.xpm_e.bits_per_pixel, &ray_info.xpm_e.line_length,
			&ray_info.xpm_e.endian);
	return (ray_info.xpm_e);
}

t_data	ft_xpm_to_image_w(t_rcst ray_info)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	ray_info.xpm_w.img = mlx_xpm_file_to_image(ray_info.window.mlx,
			ray_info.start.w_texture, &a, &b);
	ray_info.xpm_w.addr = mlx_get_data_addr(ray_info.xpm_w.img,
			&ray_info.xpm_w.bits_per_pixel, &ray_info.xpm_w.line_length,
			&ray_info.xpm_e.endian);
	return (ray_info.xpm_w);
}

t_data	ft_xpm_to_image_sprite(t_rcst ray_info)
{
	int	a;
	int	b;

	a = 64;
	b = 64;
	ray_info.xpm_sprite.img = mlx_xpm_file_to_image(ray_info.window.mlx,
			ray_info.start.sprite_texture, &a, &b);
	ray_info.xpm_sprite.addr = mlx_get_data_addr(ray_info.xpm_sprite.img,
			&ray_info.xpm_sprite.bits_per_pixel,
			&ray_info.xpm_sprite.line_length, &ray_info.xpm_sprite.endian);
	return (ray_info.xpm_sprite);
}
