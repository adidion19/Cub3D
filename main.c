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

int		main(int ac, char **av)
{
	int		i;
	t_map	start;

	i = 0;
	start.start = 0;
	if (ac == 2 || ac == 3)
		start = ft_parse_init(av[1]);
	else if (ac == 1 || ac > 3)
		printf("Error\nNombre d'arguments invalide\n");
	if (ft_error(start) == 0)
		return (0);
	ft_mlx(start);
	return (0);
}
