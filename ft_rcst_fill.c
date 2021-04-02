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

t_rcst      ft_rcst_fill_4(t_rcst ray_info)
{
    if (ray_info.ray_dir_x < 0)
    {
        ray_info.step_x = -1;
        ray_info.side_dest_x = (ray_info.pos_x - ray_info.map_x) * ray_info.delta_dist_x;
    }
    else
    {
        ray_info.step_x = 1;
        ray_info.side_dest_x = (ray_info.map_x + 1.0 - ray_info.pos_x) * ray_info.delta_dist_x;
    }
    if (ray_info.ray_dir_y < 0)
    {
        ray_info.step_y = -1;
        ray_info.side_dest_y = (ray_info.pos_y - ray_info.map_y) * ray_info.delta_dist_y;
    }
    else
    {
        ray_info.step_y = 1;
        ray_info.side_dest_y = (ray_info.map_y + 1.0 - ray_info.pos_y) * ray_info.delta_dist_y;
    }
    return (ray_info);
}

t_rcst      ft_rcst_fill_3(t_rcst ray_info)
{
    ray_info.map_x = (int)ray_info.pos_x;
    ray_info.map_y = (int)ray_info.pos_y;
    ray_info.delta_dist_x = fabs(1 / ray_info.ray_dir_x);
    ray_info.delta_dist_y = fabs(1 / ray_info.ray_dir_y);
    //if (ray_info.ray_dir_y == 0)
    //    ray_info.delta_dist_x = 0;
    //else
    //{
    //    if (ray_info.ray_dir_x == 0)
    //        ray_info.delta_dist_x = 1;
    //    else
    //        ray_info.delta_dist_x = fabs(1 / ray_info.ray_dir_x);
    //}
    //if (ray_info.ray_dir_x == 0)
    //    ray_info.delta_dist_y = 0;
    //else
    //{
    //    if (ray_info.ray_dir_y == 0)
    //        ray_info.delta_dist_y = 1;
    //    else
    //        ray_info.delta_dist_y = fabs(1 / ray_info.ray_dir_x);
    //}
    ray_info.hit = 0;
    return (ray_info);
}

t_rcst        ft_rcst_calculate(t_rcst ray_info)
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
        if (ray_info.start.tab[ray_info.map_x][ray_info.map_y] != 9 && ray_info.start.tab[ray_info.map_x][ray_info.map_y] != 3)
            ray_info.hit = 1;
    }
    if (ray_info.side == 0)
        ray_info.perp_wall_dist = (ray_info.map_x - ray_info.pos_x + (1 - ray_info.step_x) / 2) / ray_info.ray_dir_x;
    else
        ray_info.perp_wall_dist = (ray_info.map_y - ray_info.pos_y + (1 - ray_info.step_y) / 2) / ray_info.ray_dir_y;
    return (ray_info);
}

t_rcst        ft_rcst_calculate_2(t_map start, t_rcst ray_info)
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

void        ft_draw_floor_and_cell(t_rcst ray_info, int x)
{
    int i;
    int y;

    y = -1;
    i = ray_info.start.l / 2;
    while (++y < i)
        my_mlx_pixel_put(&ray_info.data, x, y, 0x00005555);
    while (++y < ray_info.start.l - 1)
        my_mlx_pixel_put(&ray_info.data, x, y, 0x0000ffff);
}

t_data      ft_data_fill(t_data img)
{
    img.img = 0;
    img.addr = 0;
    img.bits_per_pixel = 0;
    img.line_length = 0;
    img.endian = 0;
    return (img);
}

t_rcst        ft_pixel_print(t_rcst ray_info, int x)
{
    int a;
    int y;

    y = ray_info.draw_start;
    //mlx_clear_window(window.mlx, window.win);
   // else
   // ;
    a = 0x00ff0000;
    if (ray_info.side == 1)
        a = 0x00fff000;
    ft_draw_floor_and_cell(ray_info, x);
    while (ray_info.draw_start++ < ray_info.draw_end)
        my_mlx_pixel_put(&ray_info.data, x, y++, a);
    return (ray_info);
    //mlx_put_image_to_window(window.mlx, window.win, ray_info.data->img, 0, 0);
}

t_rcst      ft_rcst_loop(t_mlx window, t_map start, t_rcst ray_info)
{
    int c;

    c = 0;
    while (c++ < start.ll)
    {
        ray_info.cam_x = 2 * c / (double)(start.ll - 1);
        ray_info.ray_dir_x = ray_info.dir_x + ray_info.plan_x * ray_info.cam_x;
        ray_info.ray_dir_y = ray_info.dir_y + ray_info.plan_y * ray_info.cam_x;
        ray_info = ft_rcst_fill_3(ray_info);
        ray_info = ft_rcst_fill_4(ray_info);
        ray_info = ft_rcst_calculate(ray_info);
        ray_info = ft_rcst_calculate_2(start, ray_info);
        ray_info = ft_pixel_print(ray_info, c);
    }
   // mlx_clear_window(window.mlx, window.win);
    mlx_put_image_to_window(window.mlx, ray_info.window.win, ray_info.data.img, 0, 0);
    return (ray_info);
}

t_rcst      ft_rcst_fill_2(t_mlx window, t_map start, t_rcst ray_info)
{
    ray_info.plan_x = 0;
    ray_info.cam_time = 0;
    ray_info.old_time = 0;
    ray_info = ft_rcst_loop(window, start, ray_info);
    return (ray_info);
}

t_rcst        ft_rcst_fill(t_mlx window, t_map start, t_rcst ray_info)
{
    ray_info.pos_x = start.x;
    ray_info.pos_y = start.y;
    //ray_info.dir_x = -1;
    //ray_info.dir_y = 0;
    ray_info.plan_x = 0;
    ray_info.plan_y = 0;
    ray_info.dir_x = 0;
    ray_info.dir_y = 0;
    ray_info.plan_y = M_PI/4;
    if (start.start == 3) // N
    {
        ray_info.dir_x = -ray_info.plan_y;
        ray_info.plan_y = ray_info.plan_y;
    }
    else if (start.start == 5) // S
        ray_info.dir_x = -1;
    else
    {
        ray_info.dir_x = 0;
        ray_info.plan_y = M_PI/4;
    }
    if (start.start == 4) // E
        ray_info.dir_y = 1;
    else if (start.start == 6) // W
        ray_info.dir_y = -1;
    else
        ray_info.dir_y = -0.73;
    ray_info = ft_rcst_fill_2(window, start, ray_info);
    return (ray_info);
}