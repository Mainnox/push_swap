# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akremer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 14:26:56 by akremer           #+#    #+#              #
#    Updated: 2019/05/19 18:01:05 by akremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# des dossiers src pour les 2 exe diff avac petite modification des noms
# et tout benef
# 

NAME_1 = push_swap

NAME_2 = checker

LIB = libft/libftprintf.a

SRC_1 =		srcs_push_swap/ft_push_swap_ope.c			\
			srcs_push_swap/ft_check_argv.c				\
			srcs_push_swap/ft_tools.c					\
			srcs_push_swap/ft_check_reduc.c				\
			srcs_push_swap/ft_sort_push_swap.c			\
			srcs_push_swap/ft_progress.c				\
			srcs_push_swap/ft_quick_sort.c				\
			srcs_push_swap/ft_sol_char.c				\
			srcs_push_swap/ft_short_sort.c				\
			srcs_push_swap/push_swap.c

SRC_2 =		srcs_checker/checker.c						\
			srcs_checker/ft_checker_ope.c				\
			srcs_checker/ft_tools_checker.c				\
			srcs_checker/ft_visualizer.c				\
			srcs_checker/ft_check_argv_checker.c		\
			srcs_checker/ft_do_ope_checker.c

OBJ_1 = $(SRC_1:%.c=%.o)

OBJ_2 = $(SRC_2:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -I

all: $(NAME_1) $(NAME_2)


$(NAME_1): $(OBJ_1) lib
	@gcc $(OBJ_1) $(LIB) -o $(NAME_1)

$(NAME_2): $(OBJ_2) lib
	@gcc $(OBJ_2) $(LIB) -o $(NAME_2)

clean: 
	@rm -rf $(OBJ_1) && make -C ./libft/ clean
	@rm -rf $(OBJ_2) && make -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME_1)  && make -C ./libft/ fclean
	@rm -rf $(NAME_2)  && make -C ./libft/ fclean

re: fclean all

lib:
	@make -C ./libft/

save: fclean
	@git add *
	@git commit -m "Sauvegarde auto !"
	@git push

test: all
	@./$(NAME) $(ARG)

leaks1: fclean $(OBJ_1) lib
	@gcc -Wall -g $(OBJ_1) $(LIB) -o $(NAME_1)
	@valgrind --leak-check=yes ./$(NAME_1)

.PHONY: clean fclean save $(NAME_1) $(NAME_2) re all lib
