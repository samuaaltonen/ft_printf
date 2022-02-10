# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:12:01 by saaltone          #+#    #+#              #
#    Updated: 2022/02/10 13:45:59 by saaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FLAGS=-Wall -Werror -Wextra

LIBFT=./libft
LIBFT_INCLUDES=./libft/includes

FT_PRINTF_SOURCE_FILES=ft_printf.c conf.c flags.c output.c \
						conversion_string.c \
						conversion_char.c
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
