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

void        printstart(t_map start)
{
    printf("%d\n", start.x);
printf("%d\n", start.y);
printf("%d\n", start.start);
printf("%d\n", start.l);
printf("%d\n", start.ll);
printf("%s\n", start.n_texture);
printf("%s\n", start.s_texture);
printf("%s\n", start.e_texture);
printf("%s\n", start.w_texture);
printf("%s\n", start.sprite_texture);
printf("%d\n", start.floor_r);
printf("%d\n", start.floor_g);
printf("%d\n", start.floor_b);
printf("%d\n", start.cell_r);
printf("%d\n", start.cell_g);
printf("%d\n", start.cell_b);
}

int         ft_error(t_map start)
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
    else if (!start.n_texture || !start.e_texture || !start.w_texture || !start.s_texture || !start.sprite_texture)
    {
        printf("Error\nTexture undifined\n");
        return (0);
    }
    else if (!start.floor_r || !start.floor_g || !start.floor_b || !start.cell_b || !start.cell_g || !start.cell_r)
    {
        printf("Error\nColour of floor or cell undifined\n");
        return (0);
    }
    else
        return (1);
}

int         ft_mlx(t_map start)
{
    void *mlx;
    void *win;
    void *img;

    //printstart(start);
    mlx = mlx_init();
    win = mlx_new_window(mlx, start.ll, start.l, "cub3D");
    img = mlx_new_image(mlx, start.ll, start.l);
    mlx_loop(mlx);
    return (1);
}