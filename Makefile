# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoromin@student.42barcelona.com           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 11:32:52 by acoromin          #+#    #+#              #
#    Updated: 2026/05/28 12:06:30 by acoromin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = -I includes

SRC_DIR = srcs
BONUS_DIR = srcs_bonus

OBJ_DIR = objs
BONUS_OBJ_DIR = objs_bonus

HEADER = includes/ft_printf.h
BONUS_HEADER = includes/ft_printf_bonus.h

SRCS = $(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_putchar_pf.c \
	$(SRC_DIR)/ft_putnbr_pf.c \
	$(SRC_DIR)/ft_puthex_pf.c

BONUS_SRCS = $(BONUS_DIR)/ft_printf_bonus.c \
	$(BONUS_DIR)/ft_parse_format_bonus.c \
	$(BONUS_DIR)/ft_print_int_bonus.c \
	$(BONUS_DIR)/ft_print_utils_bonus.c \
	$(BONUS_DIR)/ft_utils_bonus.c \
	$(BONUS_DIR)/ft_print_uint_bonus.c \
	$(BONUS_DIR)/ft_print_hex_bonus.c \
	$(BONUS_DIR)/ft_print_char_bonus.c \
	$(BONUS_DIR)/ft_print_str_bonus.c \
	$(BONUS_DIR)/ft_print_percent_bonus.c \
	$(BONUS_DIR)/ft_print_ptr_bonus.c \
	$(SRC_DIR)/ft_putchar_pf.c \
	$(SRC_DIR)/ft_putnbr_pf.c \
	$(SRC_DIR)/ft_puthex_pf.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(BONUS_OBJ_DIR)/%.o)

MANDATORY_MARK = .mandatory
BONUS_MARK = .bonus

all: $(MANDATORY_MARK)

$(MANDATORY_MARK): $(OBJS)
	$(RM) $(NAME)
	$(AR) $(NAME) $(OBJS)
	$(RM) $(BONUS_MARK)
	touch $(MANDATORY_MARK)

bonus: $(BONUS_MARK)

$(BONUS_MARK): $(BONUS_OBJS)
	$(RM) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	$(RM) $(MANDATORY_MARK)
	touch $(BONUS_MARK)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c $(HEADER) $(BONUS_HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(RM) $(MANDATORY_MARK) $(BONUS_MARK)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
