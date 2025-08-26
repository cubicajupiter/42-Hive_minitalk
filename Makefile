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

NAME_C			:= client

NAME_S			:= server

SRCDIR_C		:= src/client
SRCDIR_S		:= src/server

SRCS_C			:= $(wildcard $(SRCDIR_C)/*.c)
OBJS_C			:= $(SRCS_C:%.c=%.o)

SRCS_S			:= $(wildcard $(SRCDIR_S)/*.c)
OBJS_S			:= $(SRCS_S:%.c=%.o)

COMPILER		:= cc
CFLAGS			:= -Wall -Wextra -Werror

INC_DIR			:= includes
PRINTF_PATH		:= $(INC_DIR)/printf
PRINTF_A		:= $(PRINTF_PATH)/libftprintf.a

INCLUDE			:= -I includes -I $(PRINTF_PATH)

RM				:= rm -f

all:			$(NAME_C) $(NAME_S)

$(PRINTF_PATH):
				git clone https://github.com/cubicajupiter/42Hive_ft_printf.git $(PRINTF_PATH)

$(PRINTF_A):		$(PRINTF_PATH)
				make -C $(PRINTF_PATH)

$(NAME_C):		$(OBJS_C) $(PRINTF_A)
				@echo "Linking $@"
				$(COMPILER) $(CFLAGS) $(OBJS_C) $(PRINTF_A) -o $@ -g

$(NAME_S):		$(OBJS_S) $(PRINTF_A)
				@echo "Linking $@"
				$(COMPILER) $(CFLAGS) $(OBJS_S) $(PRINTF_A) -o $@ -g

%.o:			%.c $(PRINTF_A)
				@echo "Compiling $<"
				$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@ -g

clean:
				@echo "Cleaning object files"
				@$(RM) $(OBJS_C) $(OBJS_S)
				@if [ -d "$(PRINTF_PATH)" ]; then make clean -C $(PRINTF_PATH); fi

fclean:			clean
				@echo "Cleaning executables & object files"
				@$(RM) $(NAME_C) $(NAME_S)
				@if [ -d "$(PRINTF_PATH)" ]; then make fclean -C $(PRINTF_PATH); fi

fclean-all:		fclean
				@echo "Removing ft_printf and its dependencies"
				make fclean-all -C $(PRINTF_PATH)
				@$(RM) -rf $(PRINTF_PATH)

re:				fclean-all all

.PHONY: all clean fclean fclean-all re
