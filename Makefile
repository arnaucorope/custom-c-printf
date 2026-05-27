# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 13:13:49 by acoromin          #+#    #+#              #
#    Updated: 2026/05/27 19:11:54 by acoromin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_bonus.c \
	ft_parse_format_bonus.c \
	ft_print_int_bonus.c \
	ft_int_utils_bonus.c \
	ft_utils_bonus.c \
	ft_putchar_pf.c \
	ft_putnbr_pf.c \
	ft_puthex_pf.c ft_print_uint_bonus.c ft_print_hex_bonus.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
