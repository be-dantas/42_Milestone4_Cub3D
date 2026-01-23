# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 16:34:11 by bedantas          #+#    #+#              #
#    Updated: 2026/01/23 14:41:54 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -O3 -lXext -lX11 -lm -lz

LIBFT_DIR	= ./libft
MLX_DIR		= ./minilibx-linux

LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I. -I$(LIBFT_DIR)

# ************************* COLORS & SILENCE ************************* #

RESET		= \033[0m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m

SILENT		= @

# ****************************** RULES ******************************* #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)[CUB3D]$(RESET)	 Compilado"
	$(SILENT)$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
	@echo "$(GREEN)[LIBFT]$(RESET)	 Compilando"
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(MLX_LIB):
	@echo "$(GREEN)[MLX]$(RESET)	 Compilando"
	$(SILENT)$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

%.o: %.c
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

# ***************************** CLEANING ***************************** #

clean:
	$(SILENT)echo "$(RED)[CLEAN]$(RESET)	 Removidos: objetos"
	$(SILENT)rm -f $(OBJS)
	$(SILENT)$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	$(SILENT)$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1

fclean: clean
	$(SILENT)echo "$(RED)[FCLEAN]$(RESET) Removidos: objetos e binário"
	$(SILENT)rm -f $(NAME)
	$(SILENT)$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re