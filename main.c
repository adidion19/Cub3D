/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adidion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:36:10 by adidion           #+#    #+#             */
/*   Updated: 2021/02/23 10:36:12 by adidion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int     main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2 || ac == 3)
        ft_parse_init(av[1]);
    else if (ac == 1 || ac > 3)
        printf("Error\nNombre d'arguments invalide\n");
    //system("leaks a.out");
    return (0);
}