# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 13:22:57 by mdarify           #+#    #+#              #
#    Updated: 2023/04/10 20:43:08 by yoyahya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SRCS = parsing/check_line.c parsing/error.c parsing/is_valid.c parsing/parser.c parsing/get_texture.c utils1/ft_atoi.c\
	parsing/read_file.c parsing/rgb.c parsing/utils.c parsing/utils1.c parsing/v_texture.c parsing/valid_map.c\
	cub/fdda.c cub/fddah.c cub/fddav.c cub/info.c cub/move.c cub/rend.c cub/rend3d.c cub/utils.c cub/texture.c cub/mouse.c\
	utils1/ft_isalpha1.c utils1/ft_isdigit1.c utils1/ft_split1.c utils1/ft_strdup1.c utils1/ft_strjoin1.c utils1/ft_substr1.c\
	utils/fcalc_nb.c utils/ft_calloc.c utils/ft_strchr.c utils/ft_strdup.c\
	utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_strrchr.c getnextline/get_next_line.c getnextline/get_next_line_utils.c\
	utils/ft_itoa.c utils/ft_sp.c cub3D.c 
 
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
	@git commit -m "--Cub3D--1337---"
	@git push

re : fclean all


.PHONY: all clean fclean  push re