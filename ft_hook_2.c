/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:01:00 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 12:01:02 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_red_press(int keycode, int i)
{
	keycode = 0;
	i = 1;
	exit(1);
}

t_rcst	*ft_go_right(t_rcst *ray_info)
{
	int	next_pos_x;
	int	next_pos_y;

	next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x
			+ (ray_info->plan_x * 0.2))][(int)ray_info->pos_y];
	next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
	[(int)(ray_info->pos_y + (ray_info->plan_y * 0.2))];
	if (next_pos_x == 9 || next_pos_x == 3 || next_pos_x == 4
		|| next_pos_x == 5 || next_pos_x == 6)
		ray_info->pos_x += ray_info->plan_x * 0.2;
	if (next_pos_y == 9 || next_pos_y == 3 || next_pos_y == 4
		|| next_pos_y == 5 || next_pos_y == 6)
		ray_info->pos_y += ray_info->plan_y * 0.2;
	ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
	return (ray_info);
}

t_rcst	*ft_go_left(t_rcst *ray_info)
{
	int	next_pos_x;
	int	next_pos_y;

	next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x
			- (ray_info->plan_x * 0.2))][(int)ray_info->pos_y];
	next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
	[(int)(ray_info->pos_y - (ray_info->plan_y * 0.2))];
	if (next_pos_x == 9 || next_pos_x == 3 || next_pos_x == 4
		|| next_pos_x == 5 || next_pos_x == 6)
		ray_info->pos_x -= ray_info->plan_x * 0.2;
	if (next_pos_y == 9 || next_pos_y == 3 || next_pos_y == 4
		|| next_pos_y == 5 || next_pos_y == 6)
		ray_info->pos_y -= ray_info->plan_y * 0.2;
	ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
	return (ray_info);
}

t_rcst	*ft_turn_left(t_rcst *ray_info)
{
	double	swap;
	double	swap_2;

	swap = ray_info->dir_x;
	ray_info->dir_x = ray_info->dir_x * cos(0.2) - ray_info->dir_y * sin(0.2);
	ray_info->dir_y = swap * sin(0.2) + ray_info->dir_y * cos(0.2);
	swap_2 = ray_info->plan_x;
	ray_info->plan_x = ray_info->plan_x * cos(0.2) - ray_info->plan_y
		* sin(0.2);
	ray_info->plan_y = swap_2 * sin(0.2) + ray_info->plan_y * cos(0.2);
	ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
	return (ray_info);
}
