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

int         ft_mlx(t_map start)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, start.ll, start.l, "cub3D");
    mlx_loop(mlx);
    return (1);
}