# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 15:15:02 by bsengeze          #+#    #+#              #
#    Updated: 2023/06/08 08:24:03 by bsengeze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = -L ./libft -lft

SRCS = $(addprefix $(SRC_DIR), \
		main.c \
		get_stack.c \
		error_handling.c \
		utils.c \
		list_utils.c \
		sort.c \
		swap_operations.c \
		push_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \
		for_mac.c)
		
##remove for_mac.c before eval

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
		$(RM) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re