# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abroslav <>broslav@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 21:40:03 by abroslav          #+#    #+#              #
#    Updated: 2025/07/04 21:40:55 by abroslav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC_DIR = inc
SRC_DIR = src

LIBFT_SRCS = $(wildcard $(SRC_DIR)/libft/*.c)
PRINTF_SRCS = $(wildcard $(SRC_DIR)/ft_printf/*.c)

OBJS = $(LIBFT_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
