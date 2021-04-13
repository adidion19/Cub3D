/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:48:43 by adidion           #+#    #+#             */
/*   Updated: 2021/03/09 13:48:46 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_error(t_map start)
{
	if (start.ext == 1)
	{
		printf("Error\nInvalid file extension\n");
		return (0);
	}
	else if (start.tab == 0)
	{
		printf("Error\nMap doesn't exist\n");
		return (0);
	}
	else if (!start.x || !start.y || !start.start)
	{
		printf("Error\nPlayer's start doesn't exist\n");
		return (0);
	}
	else if (start.l <= 0 || start.ll <= 0)
	{
		printf("Error\nSize of window undifined\n");
		return (0);
	}
	else if (!start.n_texture || !start.e_texture || !start.w_texture
		|| !start.s_texture || !start.sprite_texture)
	{
		printf("Error\nTexture undifined\n");
		return (0);
	}
	else if (!start.floor_r || !start.floor_g || !start.floor_b
		|| !start.cell_b || !start.cell_g || !start.cell_r)
	{
		printf("Error\nColour of floor or cell undifined\n");
		return (0);
	}
	else
		return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char			*dst;
	unsigned int	ret;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	ret = *(unsigned int *)dst;
	return (ret);
}

int	ft_mlx(t_map start)
{
	t_mlx	window;
	t_rcst	ray_info;

	window.mlx = mlx_init();
	ray_info.data = ft_data_fill(ray_info.data);
	window.win = mlx_new_window(window.mlx, start.ll, start.l, "cub3D");
	ray_info.data.img = mlx_new_image(window.mlx, start.ll, start.l);
	ray_info.data.addr = mlx_get_data_addr(ray_info.data.img,
			&ray_info.data.bits_per_pixel, &ray_info.data.line_length,
			&ray_info.data.endian);
	ray_info.window = window;
	ray_info.start = start;
	ray_info = ft_rcst_fill(window, start, ray_info);
	ft_hook(ray_info, window);
	mlx_loop(window.mlx);
	return (1);
}
