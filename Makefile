# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 16:34:11 by bedantas          #+#    #+#              #
#    Updated: 2026/01/23 14:06:34 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -O3 -lXext -lX11 -lm -lz

MLX_DIR		= ./minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

# ************************* COLORS & SILENCE ************************* #

RESET		= \033[0m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m

SILENT		= @

# ****************************** RULES ******************************* #

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(SILENT)echo "$(GREEN)[CUB3D]$(RESET) Compilado"
	$(SILENT)$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

# ***************************** CLEANING ***************************** #

clean:
	$(SILENT)echo "$(RED)[CLEAN]$(RESET) Removidos: objetos do projeto"
	$(SILENT)rm -f $(OBJS)
	$(SILENT)$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1

fclean: clean
	$(SILENT)echo "$(RED)[FCLEAN]$(RESET) Removidos: objetos e binário"
	$(SILENT)rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re