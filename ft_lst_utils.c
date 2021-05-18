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

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = 0;
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_lstlast(*(alst));
			tmp->next = new;
		}
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new == 0)
		return ;
	new->next = *alst;
	*alst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*old_elem;

	old_elem = 0;
	while (*lst)
	{
		free((*lst)->content);
		old_elem = *lst;
		*lst = old_elem->next;
		free(old_elem);
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
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
