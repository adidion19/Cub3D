/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:36:10 by adidion           #+#    #+#             */
/*   Updated: 2021/03/08 12:16:35 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>

t_map	ft_check_save(t_map start, char *str)
{
	if (!str)
		exit(1);
	if (str[0] == '-' && str[1] == '-' && str[2] == 's' && str[3] == 'a'
		&& str[4] == 'v' && str[5] == 'e' && str[6] == '\0')
	{
		start.save = 1;
		return (start);
	}
	printf("Error\nIf you want to save, the second argument ");
	printf("should be \"--save\"\n");
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	start;
	int		i;

	i = 0;
	start.start = 0;
	if (ac == 2 || ac == 3)
		start = ft_parse_init(av[1]);
	else if (ac == 1 || ac > 3)
	{
		printf("Error\nInvalid amount of arguments\n");
		exit(1);
	}
	if (ac == 3)
		start = ft_check_save(start, av[2]);
	if (ft_error(start) == 0)
		exit(1);
	ft_mlx(start);
	return (0);
}
