# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 17:12:52 by hbally            #+#    #+#              #
#    Updated: 2019/01/25 16:09:09 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Dir Variables

LIBPATH		:=	.

LIBDIRS		:=	$(LIBPATH)/libft				\
				$(LIBPATH)/libpushswap			\
				$(LIBPATH)/libpsviz				\
				$(LIBPATH)/libpsviz/minilibx

SRCSDIRS	:=	srcs_checker					\
				srcs_push_swap

.PHONY		:	all
all			:	libs subsystems

# Main Targets

.PHONY		:	subsystems
subsystems	:
				@$(foreach DIR, $(SRCSDIRS), $(MAKE) -C $(DIR) | grep -v "Nothing" || true ;)

# Make Libs

.PHONY		:	libs
libs		:
				@$(foreach LIB, $(LIBDIRS), make -C $(LIB) | grep -v "Nothing" || true ;)

# Cleanup

.PHONY		:	clean
clean		:
				@$(foreach DIR, $(SRCSDIRS), $(MAKE) -C $(DIR) clean ;)
				@$(foreach LIB, $(LIBDIRS), $(MAKE) -C $(LIB) clean ;)

.PHONY		:	fclean
fclean		:	clean
				@$(foreach DIR, $(SRCSDIRS), $(MAKE) -C $(DIR) fclean ;)
				@$(foreach LIB, $(LIBDIRS), $(MAKE) -C $(LIB) fclean ;)

.PHONY		:	re
re			:	fclean all
