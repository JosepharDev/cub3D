NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = getnextline/get_next_line.c getnextline/get_next_line_utils.c parsing/check_line.c parsing/error.c parsing/is_valid.c\
		utils/ft_isalpha.c utils/ft_isdigit.c utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_substr.c\
		parsing/parser.c parsing/read_file.c parsing/rgb.c parsing/utils.c parsing/utils1.c parsing/v_texture.c\
		parsing/valid_map.c cub_3d/dda.c cub_3d/draw.c cub_3d/position.c cub_3d/render_3d.c  cub_3d/texture.c cub_3d/utils.c\
		cub_3d/help.c cub3D.c 
 
OBJ = $(SRCS:.c=.o)
MLX_FLAGS    = -lmlx -framework OpenGL -framework Appkit


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME)
push:
	@make fclean
	@git add .
	@git commit -m "----Cub3D----1337---"
	@git push

re : fclean all