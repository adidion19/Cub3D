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

char        *ft_r_line(t_list *lst)
{
    int i;
    char *line;

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

t_list		*ft_lst_fill_3(int fd)
{
	char	*line;
	t_list	*lst;
    int i;

	lst = 0;
    i = 0;
	while (1)
    {
        line = get_next_line_2(fd, &line);
        if (!line[i])
            break;
        lst = ft_lst_fill_2(lst, line);
    }
	return (lst);
}

t_map       ft_window_size(t_map start, int fd)
{
    char    *str;
    t_list *lst;
    int i;

    i = 0;
    lst = ft_lst_fill_3(fd);
    str = ft_r_line(lst);
    if (!str[0])
        printf("Error\nResolution de l'ecran indefinie\n");
    while (str[i] && (str[i] == ' ' || str[i] == 'R'))
        i++;
    if (str[i] >= '1' && str[i] <= '9')
        start.ll = ft_atoi(((char*)str) + i);
    while (str[i] && str[i] >= '0' && str[i] <= '9')
        i++;
    while (str[i] == ' ')
        i++;
    if (str[i] >= '1' && str[i] <= '9')
        start.l = ft_atoi(((char*)str) + i);
    return (start);
}