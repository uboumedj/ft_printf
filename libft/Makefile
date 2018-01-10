# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:14:53 by uboumedj          #+#    #+#              #
#    Updated: 2018/01/10 17:23:45 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CCFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRCDIR = srcs
OBJDIR = obj
INCDIR = inc

.PHONY: all $(NAME) clean fclean re

SRC = mem/ft_memset.c mem/ft_memcpy.c mem/ft_memccpy.c mem/ft_memmove.c \
		  mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memalloc.c mem/ft_memdel.c \
		  mem/ft_bzero.c \
		  str/ft_strlen.c str/ft_strsplit.c str/ft_strctrim.c str/ft_strtrim.c \
		  str/ft_strjoin_i.c str/ft_strdup.c str/ft_strcpy.c str/ft_strncpy.c \
		  str/ft_strcat.c str/ft_strncat.c str/ft_strlcat.c str/ft_strchr.c \
		  str/ft_strrchr.c str/ft_strstr.c str/ft_strnstr.c str/ft_strcmp.c \
		  str/ft_strncmp.c str/ft_strnew.c str/ft_strdel.c str/ft_strclr.c \
		  str/ft_striter.c str/ft_striteri.c str/ft_strsub.c str/ft_strmap.c \
		  str/ft_strmapi.c str/ft_strequ.c str/ft_strnequ.c str/ft_strjoin.c \
		  str/ft_strrev.c str/ft_atoi.c str/ft_itoa.c str/ft_strtonum.c str/ft_wstrlen.c \
		  str/ft_wstrnlen.c str/ft_strnlen.c \
		  char/ft_isalpha.c char/ft_isdigit.c char/ft_isalnum.c char/ft_isascii.c \
		  char/ft_isprint.c char/ft_isupper.c char/ft_islower.c char/ft_isspace.c \
		  char/ft_isblank.c char/ft_toupper.c char/ft_tolower.c char/ft_wcharlen.c \
		  display/ft_putchar.c display/ft_putstr.c display/ft_putendl.c \
		  display/ft_putnbr.c display/ft_putstr_i.c display/ft_putchar_fd.c \
		  display/ft_putstr_fd.c display/ft_putendl_fd.c display/ft_putnbr_fd.c \
		  display/ft_putwstr.c display/ft_putwchar.c display/ft_putspace.c \
		  display/ft_putlenchar.c display/ft_putlenstr.c display/ft_putlenstr.c \
		  display/ft_putlenwstr.c \
		  list/ft_lstnew.c list/ft_lstdelone.c list/ft_lstdel.c list/ft_lstadd.c \
		  list/ft_lstiter.c list/ft_lstmap.c \
		  math/ft_abs.c math/ft_sqrt.c math/ft_max.c math/ft_min.c math/ft_pow.c \
		  math/ft_toneg.c math/ft_nbrlen.c math/ft_unbrlenbase.c

#ALLOWED EXTENSIONS

EXTENSIONS = .c .s

# SPECIAL CHARS

LOG_CLEAR        = \033[2K
LOG_UP             = \033[A
LOG_NOCOLOR        = \033[0m
LOG_BLACK        = \033[1;30m
LOG_RED            = \033[1;31m
LOG_GREEN        = \033[1;32m
LOG_YELLOW        = \033[1;33m
LOG_BLUE        = \033[1;34m
LOG_VIOLET        = \033[1;35m
LOG_CYAN        = \033[1;36m
LOG_WHITE        = \033[1;37m

# **************************************************************************** #

.PHONY: all $(NAME) build clean fclean re

.SILENT:

SRC := $(filter $(addprefix %, $(EXTENSIONS)), $(SRC))

SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))

OBJS_DIRS = $(sort $(dir $(OBJS)))

INCS_DIRS = $(addsuffix /, $(INCDIR))

INCS = $(addprefix -I , $(INCS_DIRS))

all: $(NAME)

$(NAME): build $(LIBS) $(OBJS)
	echo "$(LOG_CLEAR)$(NAME)$(LOG_YELLOW)assembling...$(LOG_NOCOLOR)$(LOG_UP)"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	echo "$(LOG_GREEN)$(NAME)$(LOG_YELLOW).......compiled\t✓$(LOG_NOCOLOR)"

build:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJS_DIRS)

clean:
	rm -rf $(OBJDIR)
	echo "$(LOG_YELLOW)Library object directory removed\t$(LOG_RED)✓$(LOG_NOCOLOR)"

fclean: clean
	rm -f $(NAME)
	echo "$(LOG_YELLOW)Library .a file deleted\t\t\t$(LOG_RED)✓$(LOG_NOCOLOR)"

re: fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	gcc -c -o $@ $< $(INCS) $(CCFLAGS)
