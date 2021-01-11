# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 12:40:21 by mhogg             #+#    #+#              #
#    Updated: 2021/01/12 00:25:28 by mhogg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_processor.c libft.c print_d_i_x_u.c print_c_s.c print_p.c
HEADER = ft_printf.h
OBJ = $(SRC:%.c=%.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re