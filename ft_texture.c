/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:55:07 by adidion           #+#    #+#             */
/*   Updated: 2021/03/11 10:55:09 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char        *ft_n_texture(t_list *lst)
{
    int i;
    char *line;

    while (lst)
    {
        i = 0;
        line = lst->content;
        if (line[i++] == 'N')
            if (line[i++] == 'O')
                if (line[i++] == ' ')
                    if (line[i++] == '.')
                        if (line[i++] == '/')
                            break;
        lst = lst->next;
    }
    return (((char*)line) + i);
}

char        *ft_s_texture(t_list *lst)
{
    int i;
    char *line;

    while (lst)
    {
        i = 0;
        line = lst->content;
        if (line[i++] == 'S')
            if (line[i++] == 'O')
                if (line[i++] == ' ')
                    if (line[i++] == '.')
                        if (line[i++] == '/')
                            break;
        lst = lst->next;
    }
    return (((char*)line) + i);
}

char        *ft_e_texture(t_list *lst)
{
    int i;
    char *line;

    while (lst)
    {
        i = 0;
        line = lst->content;
        if (line[i++] == 'E')
            if (line[i++] == 'A')
                if (line[i++] == ' ')
                    if (line[i++] == '.')
                        if (line[i++] == '/')
                            break;
        lst = lst->next;
    }
    return (((char*)line) + i);
}

char        *ft_w_texture(t_list *lst)
{
    int i;
    char *line;

    while (lst)
    {
        i = 0;
        line = lst->content;
        if (line[i++] == 'W')
            if (line[i++] == 'E')
                if (line[i++] == ' ')
                    if (line[i++] == '.')
                        if (line[i++] == '/')
                            break;
        lst = lst->next;
    }
    return (((char*)line) + i);
}

char        *ft_sprite_texture(t_list *lst)
{
    int i;
    char *line;

    while (lst)
    {
        i = 0;
        line = lst->content;
        if (line[i++] == 'S')
                if (line[i++] == ' ')
                    if (line[i++] == '.')
                        if (line[i++] == '/')
                            break;
        lst = lst->next;
    }
    return (((char*)line) + i);
}