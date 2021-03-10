# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adidion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 10:35:43 by adidion           #+#    #+#              #
#    Updated: 2021/03/09 15:22:33 by adidion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	ft_parse.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_lst_utils.c\
		ft_lst_utils_2.c\
		ft_tab_int.c\
		ft_fill_start_struct.c\
		ft_test_map.c\
		main.c\
		ft_mlx.c\
		ft_window_size.c\
		ft_atoi.c\

CFLAGS = -Wall -Wextra -Werror

LINK = ar rc

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJS) 
	gcc -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: re clean fclean all
