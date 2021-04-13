/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:28:21 by adidion           #+#    #+#             */
/*   Updated: 2021/03/09 10:19:45 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_list	*ft_lstadd_back(t_list *alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return (0);
	if (!alst)
	{
		alst = new;
		return (new);
	}
	temp = ft_lstlast(alst);
	temp->next = new;
	new->next = 0;
	return (alst);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new == 0)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (!*lst || !del)
		return ;
	while (*lst != 0)
	{
		(*del)((*lst)->content);
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
	*lst = 0;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	lst = 0;
}

void	ft_lstiter(t_list *lst, int (*f)(const char*, ...))
{
	if (lst && (*f))
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
