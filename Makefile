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

NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft/libft.a
INCLUDES	=	-I inc -I libft/inc

#Directory structure
SRC_DIR	=	src
OBJ_DIR	=	obj

#Source files
SRCS	=	main.c \
			handle_errors.c \
			input_check.c \
			large_sort.c \
			node_operations.c \
			parse_elements.c \
			push_cost_1.c \
			push_cost_2.c \
			push_operations.c \
			reverse_rotation.c \
			rotate_operations.c \
			small_sort.c \
			split.c \
			stack_init.c \
			stack_utils.c \
			swap_operations.c

#Object files
OBJS	= $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

#Rules
all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@make -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:	all clean fclean re bonus
