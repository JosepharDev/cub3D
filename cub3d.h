/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:16 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/20 20:03:32 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "getnextline/get_next_line.h"

typedef struct s_textur
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceil;
}t_textur;

typedef struct s_position
{
	int	px;
	int	py;
}t_position;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	t_textur	*textur;
	char		start_p;
	int			floor_c;
	int			ceil_c;
	t_position	player;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		size;
	char	*fd_name;
	t_map	*map;
}t_game;

//////////  error ///////
void	ft_error(char *str, char *fre);

///////		utils /////////
void	line_del(t_map *map);
void	free_matrix(char **mx);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		get_mlen(char **str);
int		get_height(char **str);
void	map_withspace(t_map *map);
void	parser(t_game *game, char *name);
int		is_map(char *line);
int		white_s(char *line);
int		is_valid(char *arg);
int		check_name(char *name);
char	*get_last(char *name);
int		ft_strlen(char *str);
int		read_file(t_game *game, int fd);
void	store_map(t_game *game, char *line);
void	check_line(t_game *game, char *line);
int		get_texture(t_game *game, char *line);
int		len_matrix(char **arr);
char	**dup_matrix(char **arr, char *line);
int		is_texture(char *line);
void	rgb_f(t_map *map);
void	rgb_c(t_map *map);
void	v_texture(t_map *map);
void	valid_map(t_map *map);
void	get_player(t_map *map);
int	texture_line(char *line);

#endif