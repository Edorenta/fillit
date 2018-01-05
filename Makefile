# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2018/01/05 14:00:07 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = fillit
LIB   = libft.a
CC    = clang
FLAGS = -Wall -Wextra -Werror
HEAD  = -I fillit.h
SRC   = src_{check_grid,txt_to_tab,bitshift,backtrack,print_grid,block_init}.c \
		libft/libft.a \
		main.c

all:	$(NAME)

build_lib:
	$(MAKE) -C libft

$(NAME):	build_lib
	$(CC) $(FLAGS) $(SRC) $(HEAD) -o $(NAME)

clean_lib:
	$(MAKE) -C libft clean

clean: clean_lib

fclean_lib:
	$(MAKE) -C libft fclean

fclean:	fclean_lib
	/bin/rm -rf $(NAME)

re:	fclean all

.PHONY: all build_lib clean_lib fclean_lib clean fclean re
