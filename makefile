# Variables
NAME = pipex
CC = cc

# Library Directories
FT_PRINTF_DIR = ./ft_printf
FT_GET_NEXT_LINE_DIR = ./getnext
FT_LIBFT_DIR = ./libft

# Libraries and Flags
FT_PRINTF = -L$(FT_PRINTF_DIR) -lftprintf
FT_GET_NEXT_LINE = -L$(FT_GET_NEXT_LINE_DIR) -lgetnext
FT_LIBFT = -L$(FT_LIBFT_DIR) -lft

CFLAGS = -g -Wall -Wextra -Werror\
         -I$(FT_PRINTF_DIR) \
         -I$(FT_GET_NEXT_LINE_DIR) \
         -I$(FT_LIBFT_DIR)

LDFLAGS = $(FT_PRINTF) $(FT_GET_NEXT_LINE) $(FT_LIBFT)

SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/env.c $(SRC_DIR)/args.c $(SRC_DIR)/childs.c \
	  $(SRC_DIR)/utils.c
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
