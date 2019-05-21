# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:12:52 by hbally            #+#    #+#              #
#    Updated: 2019/02/07 19:29:38 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	../push_swap

# Dir Variables

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

TESTDIR				=	_test

LIBSPATH			=	..

LIBDIRS				:=	$(LIBSPATH)/libft			\
						$(LIBSPATH)/libpushswap

INCDIR				:=	$(LIBDIRS:%=%/includes) 	\
						../includes					\
						includes

# File Variables

SRCS_RAW			:=	main.c					\
						cmd_print.c				\
						cmd_add.c				\
						solver.c				\
						quick_split.c			\
						quick_help.c			\
						quick_deplete.c			\
						quick_load.c			\
						quick_move.c			\
						smolsort.c				\
						smolsort_three.c

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

LIBFILES			:=	$(foreach LIB, $(LIBDIRS), $(LIB)/$(notdir $(LIB)).a)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

INCLUDES			:=	$(addprefix -I ,$(INCDIR))

INCLIBS				:=	$(foreach LIB,$(LIBDIRS),-L $(LIB) $(subst lib,-l,$(notdir $(LIB))))

# Main Target

all					:	libs $(NAME)

$(NAME)				: 	$(OBJS) $(LIBFILES)
						$(CC) -o $@ $(CFLAGS) $(INCLIBS) $(OBJS)

# Make Libs

.PHONY				:	libs
libs				:
						@$(foreach LIB, $(LIBDIRS), make -C $(LIB);)

# Objs Target

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p objs
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -MMD -c $<

# Cleanup

.PHONY				:	clean
clean				:
						rm -f $(OBJS) $(DEPENDENCIES)
						rm -rf $(OBJSDIR)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)

.PHONY				:	re
re					:	fclean all
