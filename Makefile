# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:12:01 by saaltone          #+#    #+#              #
#    Updated: 2022/02/14 12:29:45 by saaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FLAGS=-Wall -Werror -Wextra -O3

LIBFT=./libft
LIBFT_INCLUDES=./libft/includes

FT_PRINTF_SOURCE_FILES=ft_printf.c \
						conf.c \
						flags.c \
						width.c \
						precision.c \
						length.c \
						output.c \
						conversion.c \
						conversion_skip.c \
						conversion_string.c \
						conversion_char.c \
						conversion_pointer.c \
						conversion_n.c \
						conversion_hexadecimal.c \
						conversion_octal.c
FT_PRINTF_SOURCES=$(FT_PRINTF_SOURCE_FILES:%.c=srcs/%.c)
FT_PRINTF_OBJECTS=$(FT_PRINTF_SOURCE_FILES:.c=.o)
FT_PRINTF_INCLUDES=./includes

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -I $(FT_PRINTF_INCLUDES) -I $(LIBFT_INCLUDES) -c $(FT_PRINTF_SOURCES)
	ar rcs $(NAME) $(FT_PRINTF_OBJECTS)

all: $(NAME)

clean:
	/bin/rm -f $(FT_PRINTF_OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

comp:
	gcc $(FLAGS) -I $(FT_PRINTF_INCLUDES) -I $(LIBFT_INCLUDES) -c $(FT_PRINTF_SOURCES)
	ar rcs $(NAME) $(FT_PRINTF_OBJECTS)

re: fclean all

.PHONY: all clean fclean comp re
