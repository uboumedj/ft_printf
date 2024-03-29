# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/31 12:39:51 by uboumedj          #+#    #+#              #
#    Updated: 2018/01/10 17:25:08 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

SRCS =	ft_printf_bint.c \
			ft_printf_char.c \
			ft_printf_hexint.c \
			ft_printf_int.c \
			ft_printf_oint.c \
			ft_printf_ptr.c \
			ft_printf_str.c \
			ft_printf_uint.c \
			ft_printf.c \
			print_flag.c \
			parse_flags.c \
			do_flag.c

INC = ft_printf.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;34mft_printf\033[1;32m.....compiled\t✓\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) -Iinclude -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mft_printf\033[1;33m object files removed\t\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mft_printf\033[1;33m library .a file deleted\t\033[1;31m✓\033[0m"

re: fclean all
