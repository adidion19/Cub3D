/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:29:53 by adidion           #+#    #+#             */
/*   Updated: 2021/03/09 10:21:02 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_list			*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *fin;
	t_list *temp;

	if (!lst || !f)
		return (0);
	if (!(temp = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	fin = temp;
	lst = lst->next;
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&fin, del);
			return (fin);
		}
		lst = lst->next;
		ft_lstadd_back(fin, temp);
	}
	return (fin);
}

t_list			*ft_lstnew(char *content)
{
	t_list	*new;

	if (!content)
		return (0);
	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

int				ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
