NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = -L ./libft -lft
INCS	= -I ./includes/

SRC =	main.c \
		get_stack.c \
		error_handling.c \
		utils.c \
		list_utils.c \
		sort.c \
		sort_2.c \
		sort_utils.c \
		do_best_move.c \
		do_best_move_utils.c \
		swap_operations.c \
		push_operations.c \
		rotate_operations.c \
		reverse_rotate_operations.c \
		for_mac.c \
		
##remove for_mac.c before eval
SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJ		= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ $(INCS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
		make -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)


clean:
		rm -rf $(OBJ_DIR)
		@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
		$(RM) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re