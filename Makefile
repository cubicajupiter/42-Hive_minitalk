# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:19:53 by jvalkama          #+#    #+#              #
#    Updated: 2025/05/13 15:29:53 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C			= client

NAME_S			= server

SRCS_C			= client.c
OBJS_C			= $(SRCS_C:%.c=%.o)

SRCS_S			= server.c
OBJS_S			= $(SRCS_S:%.c=%.o)

COMPILER		= cc
CFLAGS			= -Wall -Wextra -Werror

INCLUDE			= -Ift

RM			= rm -f

all:			$(NAME_C) $(NAME_S)

$(NAME_C):		$(OBJS_C)

$(NAME_S):		$(OBJS_S)

%.o:			%.c
				@echo "Compiling $<"
				$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
				@echo "Cleaning object files"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "Cleaning executables & object files"
				@$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re
