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

t_list	*ft_lst_fill_2(t_list *lst, char *str)
{
	if (!lst)
		lst = ft_lstnew(str);
	else
		lst = ft_lstadd_back((lst), ft_lstnew(str));
	return (lst);
}
