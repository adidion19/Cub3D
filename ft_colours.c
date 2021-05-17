/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:11:26 by adidion           #+#    #+#             */
/*   Updated: 2021/03/11 16:11:28 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_map	ft_triple_atoi_floor(t_map start, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	start.floor_r = ft_atoi(((char *)str) + i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	start.floor_g = ft_atoi(((char *)str) + i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	start.floor_b = ft_atoi(((char *)str) + i);
	if (start.floor_b > 256 || start.floor_r > 256 || start.floor_g > 256)
		printf("Error\nInvalid floor color\n");
	if (start.floor_b > 256 || start.floor_r > 256 || start.floor_g > 256)
		exit(1);
	return (start);
}

t_map	ft_colours_floor(t_map start, t_list *lst)
{
	int		i;
	char	*line;

	while (lst)
	{
		i = 0;
		line = lst->content;
		if (line && line[i++] == 'F')
			if (line[i++] == ' ')
				start = ft_triple_atoi_floor(start, ((char *)line) + i);
		lst = lst->next;
	}
	return (start);
}

t_map	ft_triple_atoi_cell(t_map start, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	start.cell_r = ft_atoi(((char *)str) + i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	start.cell_g = ft_atoi(((char *)str) + i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
		i++;
	start.cell_b = ft_atoi(((char *)str) + i);
	if (start.cell_b > 256 || start.cell_r > 256 || start.cell_g > 256)
		printf("Error\nInvalid cell color\n");
	if (start.cell_b > 256 || start.cell_r > 256 || start.cell_g > 256)
		exit(1);
	return (start);
}

t_map	ft_colours_cell(t_map start, t_list *lst)
{
	int		i;
	char	*line;

	while (lst)
	{
		i = 0;
		line = lst->content;
		if (line && line[i++] == 'C')
			if (line[i++] == ' ')
				start = ft_triple_atoi_cell(start, ((char *)line) + i);
		lst = lst->next;
	}
	return (start);
}
