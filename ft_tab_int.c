/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:12:34 by adidion           #+#    #+#             */
/*   Updated: 2021/03/09 10:19:05 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_value_int(char c)
{
	if (c == ' ')
		return (7);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (9);
	else if (c == '2')
		return (2);
	else if (c == 'N')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'S')
		return (5);
	else if (c == 'W')
		return (6);
	else
		return (8);
}

int	*ft_free_tab(int **a)
{
	int	b;

	b = 0;
	if (!a)
		exit(1);
	while (a[b])
	{
		free(a[b]);
		b++;
	}
	free(a);
	exit(1);
}

int	*ft_fill_one_entry(char *str)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	j = ft_strlen(str);
	tab = malloc(sizeof(int) * j + 1);
	if (!tab)
		exit(1);
	while (str[i])
	{
		tab[i] = ft_value_int(str[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	**ft_int_tab_fill(t_list *lst, int i)
{
	int	**tab;
	int	a;

	tab = malloc(sizeof(int *) * i + 1);
	if (!tab)
		exit(1);
	a = 0;
	while (lst)
	{
		tab[a] = ft_fill_one_entry(lst->content);
		lst = lst->next;
		a++;
	}
	tab[a] = 0;
	ft_lstclear(&lst);
	return (tab);
}
