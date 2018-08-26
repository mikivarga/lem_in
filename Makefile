 NAME := lem-in

 SRC_DIR := ./src/
 OBJ_DIR := ./obj/
 INC_DIR := ./inc/
 
 SRC := 	main.c \
			read_map.c \
			get_next_line.c \
			validation_map.c \
			err_function.c \
			algorithm.c \
			room_index.c \
			print.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT := $(LIBFT_DIR)libft.a
LIBFT_DIR := ./libft/
LIBFT_INC := $(LIBFT_DIR)inc/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

CC_FLAGS := -Wall -Wextra -Werror

LINK_FLAGS := $(LIBFT_FLAGS)

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC :=gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $< $(HEADER_FLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJ)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)
		make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re