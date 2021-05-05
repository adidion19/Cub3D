/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:49:49 by adidion           #+#    #+#             */
/*   Updated: 2021/05/05 16:49:51 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) / 255 / 255 / 255);
}

int	ft_get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) / 255 / 255);
}

int	ft_get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) / 255);
}

int	ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	ft_push_image_to_window(t_rcst ray_info, t_mlx window)
{
	if (ray_info.start.save == 0)
		mlx_clear_window(window.mlx, window.win);
	if (ray_info.start.save == 0)
		mlx_put_image_to_window(window.mlx,
			ray_info.window.win, ray_info.data.img, 0, 0);
}
