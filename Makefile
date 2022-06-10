NAME = fdf
SRC = main.c bresenham.c initialyze.c parsing.c resize.c set_point.c utils.c toutou_D.c \
		fdf_utils.c color_by_z.c lil_bonus.c matrix_rotation.c make_rotation.c keycase.c \
		bonus.c bonus_color.c
# SRC = *.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
LDFLAGS = -L./libft/
LIBFT = ./libft/libft.a

%.o : %.c
	$(CC) -o $@ -c $< $

all : ${NAME}

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

clean : 
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY : re clean fclean all