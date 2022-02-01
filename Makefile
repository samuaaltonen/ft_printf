# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaltone <saaltone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:12:01 by saaltone          #+#    #+#              #
#    Updated: 2022/02/01 14:27:29 by saaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
FLAGS=-Wall -Werror -Wextra
LIBFT=./libft
LIBFT_INCLUDES=./libft/includes
SOURCES=ft_printf.c
OBJECTS=$(SOURCES:.c=.o)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -I . -I $(LIBFT_INCLUDES) -c $(SOURCES)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	/bin/rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
