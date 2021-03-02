/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:03:11 by adidion           #+#    #+#             */
/*   Updated: 2021/02/23 15:03:14 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_list        *ft_lst_fill_2(t_list *lst, char *str)
{
    if (!lst)
        lst = ft_lstnew(str);
    else
       lst = ft_lstadd_back((lst), ft_lstnew(str));
    return (lst);
} // probleme ici 

int         ft_check_line(char *line)
{
    int i;
    int bool;

    i = 0;
    bool = 0;
    if (!line)
        return (0);
    while (line[i] == '0' || line[i] == '1' || line[i] == ' ' || line[i] == '2' || line[i] == '\t' || line[i] == 'S')
    {
        if (line[i] == '0' || line[i] == '1' || line[i] == 'S')
            bool = 1;
        if ((line[i + 1] == '\n' || line[i + 1] == 0) && i > 1 && bool == 1)
            return (1);
        i++;
    }
    return (0);    
}

t_list      *ft_lst_fill(int fd)
{
    char *line;
    t_list *lst;

    lst = 0;
    line = get_next_line_2(fd, &line);
    while (!(ft_check_line(line)))
        line = get_next_line_2(fd, &line);
    while (ft_check_line(line) == 1)
    {
          lst = ft_lst_fill_2(lst, line);
        line = get_next_line_2(fd, &line);
    }
    while (lst)
    {
    if (lst->content)
      printf("%s\n", lst->content);
      lst = lst->next;
      //printf("%s\n", lst->content);
      //lst = lst->next;
    }
    return (lst);
}

int         ft_parse_count(char *str)
{
    int     ret;
    int     fd;
    char    *line;
    int     count;

    count = 0;
    fd = open(str, O_RDONLY);
    while (1 == (ret = get_next_line(fd, &line)))
        count++;
    return (count);
}

void        ft_parse_init(char *str)
{
    //int     i;
    int     fd;
    t_list  *lst;

    //i = ft_parse_count(str);
    printf("%s\n", str);
    fd = open(str, O_RDONLY);
    lst = ft_lst_fill(fd);
}