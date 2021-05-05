/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:53:33 by adidion           #+#    #+#             */
/*   Updated: 2021/05/05 11:53:41 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_bmp_header(int h, int stride, int fd)
{
	int				file;
	unsigned char	header[14];
	int				i;

	i = -1;
	while (++i < 14)
		header[i] = 0;
	file = 14 + 40 + (stride * h);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(file);
	header[3] = (unsigned char)(file >> 8);
	header[4] = (unsigned char)(file >> 16);
	header[5] = (unsigned char)(file >> 24);
	header[10] = (unsigned char)(14 + 40);
	write(fd, header, sizeof(header));
}

void	ft_bmp_info_header(int h, int w, int fd)
{
	unsigned char	header[40];
	int				i;

	i = -1;
	while (++i < 40)
		header[i] = 0;
	header[0] = (unsigned char)(40);
	header[4] = (unsigned char)(w);
	header[5] = (unsigned char)(w >> 8);
	header[6] = (unsigned char)(w >> 16);
	header[7] = (unsigned char)(w >> 24);
	header[8] = (unsigned char)(h);
	header[9] = (unsigned char)(h >> 8);
	header[10] = (unsigned char)(h >> 16);
	header[11] = (unsigned char)(h >> 24);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(3 * 8);
	write(fd, header, sizeof(header));
}

void	ft_write_color(int fd, int rgb)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(ft_get_r(rgb));
	g = (unsigned char)(ft_get_g(rgb));
	b = (unsigned char)(ft_get_b(rgb));
	write(fd, &b, sizeof(b));
	write(fd, &g, sizeof(g));
	write(fd, &r, sizeof(r));
}

void	ft_bmp_save(t_rcst ray_info)
{
	int	fd;
	int	i;
	int	j;
	int	rgb;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777);
	if (fd == -1)
		exit (1);
	i = ray_info.start.l;
	ft_bmp_header(ray_info.start.l, (ray_info.start.ll * 3) + ((4
				- (ray_info.start.ll * 3) % 4) % 4), fd);
	ft_bmp_info_header(ray_info.start.l, ray_info.start.ll, fd);
	while (--i >= 0)
	{
		j = ray_info.start.ll;
		while (--j >= 0)
		{
			rgb = my_mlx_pixel_get(&ray_info.data, ray_info.start.ll - j, i);
			ft_write_color(fd, rgb);
		}
	}
	close(fd);
	exit(1);
}
