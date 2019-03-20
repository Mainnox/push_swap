# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 14:26:56 by akremer           #+#    #+#              #
#    Updated: 2019/03/20 16:43:47 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# des dossiers src pour les 2 exe diff avac petite modification des noms
# et tout benef
# 

NAME_1 = push_swap

NAME_2 = checker

LIB = libft/libftprintf.a

SRC_C =		ft_push_swap_ope.c			\
			ft_check_argv.c				\
			ft_tools.c					\
			ft_sort_push_swap.c			\
			push_swap.c					\
			checker.c

SRC_EXE_1 = push_swap.c

SRC_EXE_2 = checker.c

INCLUDES = ft_push_swap.h

OBJ_C = $(SRC_C:%.c=%.o)

OBJ_EXE_1 = $(SRC_EXE_1:%.c=%.o)

OBJ_EXE_2 = $(SRC_EXE_2:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -I

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_C) $(OBJ_EXE_1) lib
	@gcc $(FLAGS) $(INCLUDES) -c $(SRC_C) $(SRC_EXE_1)
	@gcc $(OBJ_C) $(OBJ_EXE_1) $(LIB) -o $(NAME_1)

$(NAME_2): $(OBJ_C) $(OBJ_EXE_2) lib
	@gcc $(FLAGS) $(INCLUDES) -c $(SRC_C) $(SRC_EXE_2)
	@gcc $(OBJ_C) $(OBJ_EXE_2) $(LIB) -o $(NAME_2)

clean: 
	@rm -rf $(OBJ_C) && make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME_1) $(NAME_2) && make -C ./libft/ fclean

re: fclean all

lib:
	@make -C ./libft/

save: fclean
	@git add *
	@git commit -m "Sauvegarde auto !"
	@git push

test: all
	@./$(NAME) $(ARG)

.PHONY: clean fclean save $(NAME_1) $(NAME_2) re all lib
