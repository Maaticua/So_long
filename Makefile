# Standard
NAME				= so_long

# Directories
LIBFT_DIR			= ./Libft
MLX_DIR				= ./minilibx-linux
LIBFT				= $(LIBFT_DIR)/libft.a
MLX_LIB				= $(MLX_DIR)/libmlx.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

# Compiler and Flags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3 -I $(INC)
RM					= rm -f

# Source Files
SRCS				= $(SRC_DIR)exit.c \
					$(SRC_DIR)floodfill.c \
					$(SRC_DIR)game_movement.c \
					$(SRC_DIR)game_utils.c \
					$(SRC_DIR)map_checker.c \
					$(SRC_DIR)map_checker2.c \
					$(SRC_DIR)map_utils.c \
					$(SRC_DIR)read_map.c \
					$(SRC_DIR)so_long.c \
					$(SRC_DIR)textures_utils.c

# Object Files
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start: all

# Compilation de Libft et MinilibX
$(LIBFT):
					@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
					@$(MAKE) -C $(MLX_DIR)

# Compilation principale
all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -L$(MLX_DIR) -lmlx -lX11 -lXext
					@echo "✅ Compilation réussie !"

# Compilation des fichiers objets
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
					@$(RM) -r $(OBJ_DIR)
					@$(MAKE) clean -C $(LIBFT_DIR)
					@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
					@$(RM) $(NAME)
					@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# Phony targets
.PHONY: start all clean fclean re
