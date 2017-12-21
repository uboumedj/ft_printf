# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:14:53 by uboumedj          #+#    #+#              #
#    Updated: 2017/12/21 03:27:26 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isupper.c ft_islower.c ft_isspace.c ft_strctrim.c ft_abs.c ft_sqrt.c ft_strrev.c ft_strjoin_i.c ft_nbrlen.c ft_strtonum.c ft_toneg.c ft_putstr_i.c ft_isblank.c ft_max.c ft_min.c ft_putspace.c ft_putlenchar.c ft_nbrlen.c ft_wcharlen.c ft_putwchar.c ft_putwstr.c ft_wstrnlen.c ft_wstrlen.c ft_unbrlenbase.c ft_putlenstr.c ft_putlenwstr.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(OPTIONS) $(SOURCES)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
