# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:36:08 by saaltone          #+#    #+#              #
#    Updated: 2022/02/10 15:56:09 by saaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_putchar.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		  ft_strclr.c ft_striter.c ft_striteri.c ft_strlen.c ft_strmap.c \
		  ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c \
		  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putstr.c \
		  ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c \
		  ft_putnbr_fd.c ft_itoa.c ft_memset.c ft_bzero.c ft_memcpy.c \
		  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c \
		  ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		  ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_atoi.c \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_toupper.c ft_tolower.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		  ft_lstadd.c ft_lstput.c ft_lstiter.c ft_lstmap.c \
		  ft_putendl_fd.c ft_split_count.c ft_count_digits.c \
		  ft_putstr_color.c ft_pow.c ft_abs.c ft_bzerofree.c ft_memchr_len.c \
		  ft_lstpop.c ft_get_next_line.c ft_rgbtoint.c ft_array_create.c \
		  ft_array_insert.c ft_array_expand.c ft_array_foreach.c \
		  ft_color_between.c ft_str_isalnum.c ft_hextoint.c \
		  ft_max.c ft_min.c ft_toggle.c ft_itoa_base.c
SOURCES = $(FUNCTIONS:%.c=srcs/%.c)
OBJECTS = $(FUNCTIONS:.c=.o)
HEADERS = includes

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I./$(HEADERS) -c $(SOURCES)
	ar rcs $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
