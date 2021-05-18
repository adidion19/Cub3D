/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:03:11 by adidion           #+#    #+#             */
/*   Updated: 2021/03/08 12:14:15 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_check_line(char *line)
{
	int	i;
	int	bool;

	i = 0;
	bool = 0;
	if (!line)
		return (0);
	while (line[i] == '0' || line[i] == '1' || line[i] == ' '
		|| line[i] == '2' || line[i] == 'S' || line[i] == 'N'
		|| line[i] == 'E' || line[i] == 'W')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'S'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'W')
			bool = 1;
		if ((line[i + 1] == '\n' || line[i + 1] == 0) && i > 1 && bool == 1)
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_fill(int fd)
{
	char	*line;
	t_list	*lst;

	line = 0;
	lst = 0;
	get_next_line(fd, &line);
	while (!(ft_check_line(line)))
	{
		if (line)
			free(line);
		get_next_line(fd, &line);
	}
	lst = ft_lstnew((void *)line);
	while (ft_check_line(line) == 1)
	{
		get_next_line(fd, &line);
		ft_lstadd_back(&(lst), ft_lstnew((void *)line));
	}
	if (line)
		free(line);
	return (lst);
}

int	ft_parse_count(char *str)
{
	int		ret;
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(str, O_RDONLY);
	ft_printf_and_exit(fd);
	ret = get_next_line(fd, &line);
	free(line);
	while (1 == ret)
	{
		ret = get_next_line(fd, &line);
		free(line);
		count++;
	}
	return (count);
}

void	ft_print_tab(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%d", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

t_map	ft_parse_init(char *str)
{
	int		i;
	int		fd;
	t_list	*lst;
	t_map	start;
	int		**tab;

	lst = 0;
	i = ft_parse_count(str);
	ft_text_ext_2(str);
	fd = open(str, O_RDONLY);
	ft_printf_and_exit(fd);
	lst = ft_lst_fill(fd);
	tab = ft_int_tab_fill(lst, i);
	ft_lstclear(&lst);
	start = ft_fill_start_struct(tab, i);
	if (!(ft_test_map(start.tab)))
		start.tab = 0;
	if (!(ft_test_map(start.tab)))
		return (start);
	close(fd);
	fd = open(str, O_RDONLY);
	ft_printf_and_exit(fd);
	start = ft_window_size(str, start, fd);
	close(fd);
	return (start);
}
