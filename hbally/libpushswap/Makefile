# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:12:52 by hbally            #+#    #+#              #
#    Updated: 2019/02/08 10:12:15 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libpushswap.a

# Dir Variables

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

LIBDIR				=	..

LIBSUBDIRS			:=	$(LIBDIR)/libft

INCDIR				:=	$(LIBSUBDIRS:%=%/includes) 	\
						../includes					\
						includes					\

# File Variables

SRCS_RAW			:=	lst_add.c			\
						lst_misc.c			\
						lst_sort.c			\
						get_options.c		\
						stack_get.c			\
						stack_dup.c			\
						stack_push.c		\
						stack_swap.c		\
						stack_rotate.c		\
						stack_check.c		\
						cmd_loadindex.c		\
						cmd_apply.c			\
						clean_exit.c

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

INCLUDES			:=	$(addprefix -I ,$(INCDIR))

# Main Target

all					:	libs $(NAME)

$(NAME)				: 	$(OBJS)
						ar rc $@ $(OBJS)
						ranlib $@

# Make Libs

.PHONY				:	libs
libs				:
						@$(foreach LIB, $(LIBSUBDIRS), make -C $(LIB);)

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
