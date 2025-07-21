# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abroslav <broslav@student.42porto.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 16:05:45 by abroslav          #+#    #+#              #
#    Updated: 2025/07/10 16:32:56 by abroslav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft

# Biblioteca estática da libft
LIBFT_A = $(LIBFT_DIR)/libft.a

# Fontes e objetos (sem wildcard)
SRCS    =   $(SRC_DIR)/main.c \
            $(SRC_DIR)/handle_errors.c \
            $(SRC_DIR)/input_check.c \
            $(SRC_DIR)/large_sort.c \
            $(SRC_DIR)/node_operations.c \
            $(SRC_DIR)/parse_elements.c \
            $(SRC_DIR)/push_cost_1.c \
            $(SRC_DIR)/push_cost_2.c \
            $(SRC_DIR)/push_operations.c \
            $(SRC_DIR)/reverse_rotation.c \
            $(SRC_DIR)/rotate_operations.c \
            $(SRC_DIR)/small_sort.c \
            $(SRC_DIR)/split.c \
            $(SRC_DIR)/stack_init.c \
            $(SRC_DIR)/stack_utils.c \
            $(SRC_DIR)/swap_operations.c

OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Includes
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc

# Regra padrão
all: $(NAME)

# Regra para libft (compila só se não existir)
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar objetos, criando obj/ se necessário
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linkar executável com libft
$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Limpar arquivos objeto e diretório obj
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Limpar tudo, incluindo executável e libft
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Recompilar tudo
re: fclean all

.PHONY: all clean fclean re

