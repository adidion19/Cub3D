/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:27:10 by adidion           #+#    #+#             */
/*   Updated: 2021/03/09 17:27:11 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_r_line(t_list *lst)
{
	int		i;
	char	*line;

	while (lst)
	{
		i = 0;
		line = lst->content;
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R')
			return (line);
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_lst_fill_3(int fd)
{
	char	*line;
	t_list	*lst;
	int		i;

	lst = 0;
	i = 0;
	while (1)
	{
		line = get_next_line_2(fd, &line);
		if (!line[i] || !line)
			break ;
		lst = ft_lst_fill_2(lst, line);
	}
	return (lst);
}

t_map	ft_text(char *file, t_map start)
{
	t_list	*lst;
	int		fd;

	fd = open(file, O_RDONLY);
	lst = ft_lst_fill_3(fd);
	start.n_texture = ft_n_texture(lst);
	start.s_texture = ft_s_texture(lst);
	start.e_texture = ft_e_texture(lst);
	start.w_texture = ft_w_texture(lst);
	start.sprite_texture = ft_sprite_texture(lst);
	start = ft_colours_floor(start, lst);
	start = ft_colours_cell(start, lst);
	//ft_lstclear(&lst);
	return (start);
}

t_map	ft_window_size(char *file, t_map start, int fd)
{
	char	*str;
	t_list	*lst;
	int		i;

	i = 0;
	lst = ft_lst_fill_3(fd);
	str = ft_r_line(lst);
	while (str[i] && (str[i] == ' ' || str[i] == 'R'))
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		start.ll = ft_atoi(((char *)str) + i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] >= '1' && str[i] <= '9')
		start.l = ft_atoi(((char *)str) + i);
	start = ft_text(file, start);
	ft_lstclear(&lst);
	return (start);
}
