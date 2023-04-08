# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 13:22:57 by mdarify           #+#    #+#              #
#    Updated: 2023/04/08 11:14:42 by mdarify          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
SRCS = parsing/fmap.c parsing/felem.c parsing/collect_map.c parsing/fcolor.c\
	parsing/ft_check_file.c parsing/map_setting.c parsing/texture.c\
	cub/fdda.c cub/fddah.c cub/fddav.c cub/info.c cub/move.c cub/rend.c cub/rend3d.c cub/utils.c\
	utils/fcalc_nb.c utils/ft_calloc.c  utils/ft_split.c utils/ft_strchr.c utils/ft_strdup.c\
	utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_strrchr.c utils/gcl.c utils/util.c\
	utils/ft_itoa.c utils/ft_sp.c cub3d.c 
 
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