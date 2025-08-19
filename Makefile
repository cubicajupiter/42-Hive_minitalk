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

NAME			= _______________

SRCS			= _______________.c
OBJS			= $(SRCS:%.c=%.o)

HEADER			= _______________.h

LIBFT_PATH		= $(LIBFT_DIR)/libft.a
LIBFT_DIR		= libft

MLX_PATH		= $(MLX_DIR)/libmlx_Linux.a
MLX_DIR			= ../../mlx_linux

PRINTF_PATH		= $(PRINTF_DIR)/libftprintf.a
PRINTF_DIR		= printf

ARCHIVES		= $(LIBFT_A) $(MLX_PATH) $(PRINTF_PATH)

COMPILER		= cc
CFLAGS			= -Wall -Wextra -Werror
INCLUDE_LIBFT		= -I $(LIBFT_PATH)
INCLUDE_MLX		= -I $(MLX_PATH) -O3 -c $< -o $@

RM			= rm -f

all:			$(NAME)

$(LIBFT_A):
				make -C $(LIBFT_PATH)

$(NAME):		$(OBJS) $(ARCHIVES)
				cp $(LIBFT_A) $(NAME)
				ar -rcs $(NAME) $(OBJS)

%.o:			%.c $(HEADER)
				@echo "Compiling $<"
				$(COMPILER) $(CFLAGS) $(INCLUDE_) -c $< -o $@

clean:
				@echo "Cleaning object files in parent and libft"
				@$(RM) $(OBJS)
				make clean -C $(LIBFT_PATH)

fclean:			clean
				@echo "Cleaning library in parent and libft"
				@$(RM) $(NAME)
				make fclean -C $(LIBFT_PATH)

re:				fclean all

.PHONY: all clean fclean re
