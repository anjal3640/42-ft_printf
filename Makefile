# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankadava <ankadava@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/09 10:54:00 by ankadava          #+#    #+#              #
#    Updated: 2026/11/10 12:31:32 by ankadava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC =cc
CFLAGES = -Wall -Wextra -Werror

SRC=ft_printf.c \
	src/ft_putchar_int.c\
	src/ft_strlen.c\
	src/ft_putstr_int.c\
	src/ft_putnbr_int.c\
	src/ft_putnbr_base_int.c\
	src/ft_putptr_int.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGES) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re