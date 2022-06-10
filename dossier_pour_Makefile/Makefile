
SRC_PATH = ./src/
SRC_BONUS_PATH = ./src_bonus/
OBJ_PATH = ./obj_bonus/
OBJ_BONUS_PATH = ./obj_bonus/
MAIN_PATH = ./main/
MAIN_BONUS_PATH = ./main/
INCLUDE = I./include/
SRC_NAME = parsing.c toutou_D.c fdf_utils.c bresenham.c bresenham_utils.c \
		resize.c matrix_rotation.c get_right_color.c \
		
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

SRC_BONUS_NAME = fdf_bonus.c
SRC_BONUS = $(addprefix $(SRC_BONUS_PATH),$(SRC_BONUS_NAME))

OBJ_BONUS_NAME = $(SRC_BONUS_NAME:.c=.o)
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/,$(OBJ_BONUS_NAME))

MAIN_NAME = fdf.c
MAIN_BONUS_NAME = fdf_bonus.c

CC = gcc $(FLAGS)
FLAGS = -Wall -Werror -Wextra

NAME = fdf
LDFLAGS = -L./libft/
MLX = -lmlx -framework OpenGL -framework AppKit


$(OBJ_BONUS_PATH)%.o: $(SRC_BONUS_PATH)%.c
	mkdir $(OBJ_BONUS_PATH) 2> /dev/null || true
	$(CC) -Imlx -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(MLX) $(LDFLAGS) $(OBJ) $(MAIN) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(INCLUDE) -Imlx -c $< -o $@


bonus : $(NAME) $(MAIN)
	$(MAKE) -C ./libft
	$(CC) $(MLX) $(OBJ) $(MAIN)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re

	



