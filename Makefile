# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adidion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 10:35:43 by adidion           #+#    #+#              #
#    Updated: 2021/02/23 10:35:46 by adidion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME =	cube.a

SRCS =	ft_parse.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_lst_utils.c\
		ft_lst_utils_2.c\

OBJS = $(SRCS:.c=.o)

LINK = ar rc

all : $(NAME)

$(NAME):	$(OBJS)
	$(LINK) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re bonus clean fclean all