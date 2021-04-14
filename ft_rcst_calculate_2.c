/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rcst_calculate_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:11:01 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 14:11:04 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rcst	ft_rcst_fill_4(t_rcst ray_info)
{
	if (ray_info.ray_dir_x < 0)
	{
		ray_info.step_x = -1;
		ray_info.side_dest_x = (ray_info.pos_x - ray_info.map_x)
			* ray_info.delta_dist_x;
	}
	else
	{
		ray_info.step_x = 1;
		ray_info.side_dest_x = (ray_info.map_x + 1.0 - ray_info.pos_x)
			* ray_info.delta_dist_x;
	}
	if (ray_info.ray_dir_y < 0)
	{
		ray_info.step_y = -1;
		ray_info.side_dest_y = (ray_info.pos_y - ray_info.map_y)
			* ray_info.delta_dist_y;
	}
	else
	{
		ray_info.step_y = 1;
		ray_info.side_dest_y = (ray_info.map_y + 1.0 - ray_info.pos_y)
			* ray_info.delta_dist_y;
	}
	return (ray_info);
}

t_rcst	ft_rcst_fill_3(t_rcst ray_info)
{
	ray_info.map_x = (int)ray_info.pos_x;
	ray_info.map_y = (int)ray_info.pos_y;
	ray_info.delta_dist_x = fabs(1 / ray_info.ray_dir_x);
	ray_info.delta_dist_y = fabs(1 / ray_info.ray_dir_y);
	ray_info.hit = 0;
	return (ray_info);
}
