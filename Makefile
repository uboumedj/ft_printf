# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 15:29:39 by uboumedj          #+#    #+#              #
#    Updated: 2017/12/05 17:29:49 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/ *.c
	clang -o test_printf *.o -I libft/ -L libft/ -lft

