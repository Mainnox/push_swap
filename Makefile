# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 14:26:56 by akremer           #+#    #+#              #
#    Updated: 2019/03/20 09:48:13 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libft/libftprintf.a

SRC =		ft_push_swap_ope.c			\
			ft_check_argv.c				\
			ft_tools.c					\
			ft_sort_push_swap.c			\
			push_swap.c				

INCLUDES = ft_push_swap.c

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -I

all: $(NAME)

$(NAME): $(OBJ) lib
	@gcc $(FLAGS) $(INCLUDES) -c $(SRC)
	@gcc $(OBJ) $(LIB) -o $(NAME)

clean: 
	@rm -rf $(OBJ) && make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME) && make -C ./libft/ fclean

re: fclean all

lib:
	@make -C ./libft/

save: fclean
	@git add *
	@git commit -m "Sauvegarde auto !"
	@git push

test: all
	@./$(NAME) $(ARG)

.PHONY: clean fclean save $(NAME) re all lib
