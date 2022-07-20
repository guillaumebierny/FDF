NAME = fdf
SRC = bresenham.c initialyze.c parsing.c resize.c set_point.c utils.c toutou_D.c \
		fdf_utils.c color_by_z.c lil_bonus.c matrix_rotation.c  make_rotation.c\
		bresenham_utils.c parsing_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -framework OpenGL -framework AppKit -L./minilibx_macos -lmlx
LDFLAGS = -L./libft/
LIBFT = ./libft/libft.a
MAIN_SRC = main.c
MAIN = $(MAIN_SRC:.c=.o)
BONUS_SRC = main_bonus.c bonus.c bonus_color.c keycase.c
BONUS = $(BONUS_SRC:.c=.o)

%.o : %.c
	$(CC) -o $@ -c $< $

all : ${NAME}

$(NAME): $(OBJ) $(MAIN)
	$(MAKE) -C ./libft
	$(CC) $(MLX) $(LIBFT) $(MAIN) $(OBJ) -o $(NAME)

bonus :  $(NAME) $(BONUS)
	$(CC) $(MLX) $(LIBFT) $(BONUS) $(OBJ) -o $(NAME)


clean : 
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@rm -f $(MAIN)
	rm -f $(BONUS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY : re clean fclean all bonus