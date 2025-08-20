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

PRINTF_A		= $(PRINTF_PATH)/libftprintf.a
PRINTF_PATH		= includes/printf
INCLUDE			= -I $(PRINTF_PATH)

RM			= rm -f

all:			$(NAME_C) $(NAME_S)

$(PRINTF_A):	
			make -C $(PRINTF_PATH)

$(NAME_C):		$(OBJS_C) $(PRINTF_A)

$(NAME_S):		$(OBJS_S) $(PRINTF_A)

%.o:			%.c
				@echo "Compiling $<"
				$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@ -g

clean:
				@echo "Cleaning object files"
				@$(RM) $(OBJS_C) $(OBJS_S)
				make clean -C $(PRINTF_PATH)

fclean:			clean
				@echo "Cleaning executables & object files"
				@$(RM) $(NAME_C) $(NAME_S)
				make fclean -C $(PRINTF_PATH)

re:				fclean all

.PHONY: all clean fclean re
