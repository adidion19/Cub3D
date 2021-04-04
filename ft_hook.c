/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:29:13 by adidion           #+#    #+#             */
/*   Updated: 2021/03/22 17:29:15 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rcst            *ft_go_up(t_rcst *ray_info)
{
    int next_pos_x;
    int next_pos_y;

    next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x + (ray_info->dir_x * 0.2))]
    [(int)ray_info->pos_y];
    next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
    [(int)(ray_info->pos_y + (ray_info->dir_y * 0.2))];
    if (next_pos_x == 9 || next_pos_x == 3)
        ray_info->pos_x += ray_info->dir_x * 0.2;
    if (next_pos_y == 9 || next_pos_y == 3)
        ray_info->pos_y += ray_info->dir_y * 0.2;
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return(ray_info);
}

t_rcst            *ft_go_down(t_rcst *ray_info)
{
    int next_pos_x;
    int next_pos_y;

    next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x - (ray_info->dir_x * 0.2))]
    [(int)ray_info->pos_y];
    next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
    [(int)(ray_info->pos_y - (ray_info->dir_y * 0.2))];
    if (next_pos_x == 9 || next_pos_x == 3)
        ray_info->pos_x -= ray_info->dir_x * 0.2;
    if (next_pos_y == 9 || next_pos_y == 3)
        ray_info->pos_y -= ray_info->dir_y * 0.2;
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return(ray_info);
}

t_rcst            *ft_go_right(t_rcst *ray_info)
{
    int next_pos_x;
    int next_pos_y;

    next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x + (ray_info->plan_x * 0.2))]
    [(int)ray_info->pos_y];
    next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
    [(int)(ray_info->pos_y + (ray_info->plan_y * 0.2))];
    if (next_pos_x == 9 || next_pos_x == 3)
        ray_info->pos_x += ray_info->plan_x * 0.2;
    if (next_pos_y == 9 || next_pos_y == 3)
        ray_info->pos_y += ray_info->plan_y * 0.2;
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return(ray_info);
}

t_rcst            *ft_go_left(t_rcst *ray_info)
{
    int next_pos_x;
    int next_pos_y;

    next_pos_x = ray_info->start.tab[(int)(ray_info->pos_x - (ray_info->plan_x * 0.2))]
    [(int)ray_info->pos_y];
    next_pos_y = ray_info->start.tab[(int)(ray_info->pos_x)]
    [(int)(ray_info->pos_y - (ray_info->plan_y * 0.2))];
    if (next_pos_x == 9 || next_pos_x == 3)
        ray_info->pos_x -= ray_info->plan_x * 0.2;
    if (next_pos_y == 9 || next_pos_y == 3)
        ray_info->pos_y -= ray_info->plan_y * 0.2;
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return(ray_info);
}

t_rcst            *ft_turn_left(t_rcst *ray_info)
{
    double swap;
    double swap_2;

    swap = ray_info->dir_x;
    ray_info->dir_x = ray_info->dir_x * cos(0.2) - ray_info->dir_y * sin(0.2);
    ray_info->dir_y = swap * sin(0.2) + ray_info->dir_y * cos(0.2);
    swap_2 = ray_info->plan_x;
    ray_info->plan_x = ray_info->plan_x * cos(0.2) - ray_info->plan_y * sin(0.2);
    ray_info->plan_y = swap_2 * sin(0.2) + ray_info->plan_y * cos(0.2);
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return (ray_info);
}

t_rcst            *ft_turn_right(t_rcst *ray_info)
{
    double swap;
    double swap_2;

    swap = ray_info->dir_x;
    ray_info->dir_x = ray_info->dir_x * cos(-0.2) - ray_info->dir_y * sin(-0.2);
    ray_info->dir_y = swap * sin(-0.2) + ray_info->dir_y * cos(-0.2);
    swap_2 = ray_info->plan_x;
    ray_info->plan_x = ray_info->plan_x * cos(-0.2) - ray_info->plan_y * sin(-0.2);
    ray_info->plan_y = swap_2 * sin(-0.2) + ray_info->plan_y * cos(-0.2);
    ft_rcst_loop(ray_info->window, ray_info->start, *ray_info);
    return (ray_info);
}

int             ft_key_press(int keycode, t_rcst *ray_info)
{
    if (keycode == 53)
    {
        mlx_destroy_window(ray_info->window.mlx, ray_info->window.win);
        exit(EXIT_SUCCESS);
    }
    if (keycode == 0) // A
        ft_go_left(ray_info);
    if (keycode == 13 || keycode == 126) // W ^
        ft_go_up(ray_info);
    if (keycode == 1 || keycode == 125) // S \/
        ft_go_down(ray_info);
    if (keycode == 2) // D
        ft_go_right(ray_info);
    if (keycode == 12 || keycode == 123) // Q <
        ft_turn_left(ray_info);
    if (keycode == 14 || keycode == 124) // E >
        ft_turn_right(ray_info);
        return (0);
}

t_rcst			ft_hook(t_rcst ray_info, t_mlx window)
{
    mlx_hook(window.win, 02, 1L << 0, ft_key_press, &ray_info);
    return (ray_info);
}