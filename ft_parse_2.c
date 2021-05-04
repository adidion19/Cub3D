/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:22:57 by adidion           #+#    #+#             */
/*   Updated: 2021/04/14 12:23:00 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_char_to_int(char *str)
{
	int	*i;

	i = (int *)str;
	return (*i);
}

void	ft_text_ext_2(char *str)
{
	if (!ft_test_ext(str))
	{
		printf("Error\nInvalid extension\n");
		exit(1);
	}
}

void	ft_printf_and_exit(int fd)
{
	if (fd == -1)
	{
		printf("Error\nFile not found\n");
		exit(1);
	}
}

t_map	ft_screen_size(t_mlx window, t_map start)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(window.mlx, &x, &y);
	if (x < start.ll)
		start.ll = x;
	if (y < start.l)
		start.l = y;
	return (start);
}

t_list	*ft_lst_fill_2(t_list *lst, char *str)
{
	if (!lst)
		lst = ft_lstnew(str);
	else
		ft_lstadd_back(&(lst), ft_lstnew(str));
	return (lst);
}
