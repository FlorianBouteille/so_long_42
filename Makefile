CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

# Dossiers
LIBFT_DIR = ./shared_libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
OBJ_DIR = ./obj
MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11

# Fichiers sources
SRC = main.c open_map.c image.c check_map.c check_map_2.c check_map_3.c draw_map.c update_map.c utils.c init.c play.c

# Objets
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Nom des exécutables
NAME = so_long

# Règles de compilation
all: $(LIBFT) $(MLX_DIR)/libmlx.a $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft $(MLX_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all
