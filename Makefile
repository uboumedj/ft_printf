# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/31 12:39:51 by uboumedj          #+#    #+#              #
#    Updated: 2017/12/31 13:29:40 by uboumedj         ###   ########.fr        #
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
			ft_printflags.c \
			ft_setflags.c

INC = ft_printf.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

%.o: %.c
	@mkdir -p temp
	@$(CC) $(FLAGS) -Iinclude -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mft_printf/libft\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mft_printf/libft\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
