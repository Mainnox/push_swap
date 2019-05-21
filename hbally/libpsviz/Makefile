# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:12:52 by hbally            #+#    #+#              #
#    Updated: 2019/02/08 10:06:18 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libpsviz.a

# Dir Variables

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

LIBDIR				=	..

LIBSUBDIRS			:=	$(LIBDIR)/libft				\
						$(LIBDIR)/libpushswap		\
						minilibx

INCDIR				:=	$(LIBSUBDIRS:%=%/includes) 	\
						includes					\
						../includes

# File Variables

SRCS_RAW			:=	drawline.c			\
						ref.c				\
						startup.c			\
						hooks.c				\
						render.c			\
						render_stacks.c		\
						render_background.c	\
						render_lastmove.c	\
						render_ui.c			\
						colors.c			\
						window_exit.c		\
						window_start.c		\
						window_size.c		\
						vizlst.c			\
						vizlst_sort.c		\
						steps.c

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
