# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 13:13:49 by acoromin          #+#    #+#              #
#    Updated: 2026/05/20 13:27:58 by acoromin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

COMMON_SRCS = ft_putchar_pf.c ft_putnbr_pf.c ft_puthex_pf.c
SRCS = ft_printf.c $(COMMON_SRCS)
BONUS_SRCS = ft_printf_bonus.c ft_parse_format_bonus.c ft_print_flags_bonus.c \
			$(COMMON_SRCS)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: $(LIBFT) $(BONUS_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
