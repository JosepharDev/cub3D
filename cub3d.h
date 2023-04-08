/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:34:27 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 13:21:15 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define X_EVENT_KEY_EXIT       17
# define ESC       53
# define FOV 66.66
# define SPEED 15
# define WIDTH 1500
# define HEIGHT 1200
# define TILE_SIZE 30

# define UPR 1
# define UPL -1
# define DOWNR 0
# define DOWNL -2
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ROTR 124
# define ROTL 123

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void	*s, size_t	n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *s);

typedef struct s_textur
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}	t_textur;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			height;
	t_textur	*textur;
	char		starting_pos;
	int			floor_color;
	int			ceilling_color;
	t_vector	player;

}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map_contant;
	int		size;
	char	*fd;
	t_map	*map;
}	t_game;

typedef struct s_point
{
	double	x;
	double	signx;
	double	y;
	double	signy;
}	t_point;

typedef struct s_img{
	void	*img;
	int		w;
	int		h;
	char	*addr;
	char	*dst;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_win{
	void	*mlx_p;
	void	*mlx_w;
	void	*img_0;
	void	*img_1;
	void	*img_p;
}	t_win;

typedef struct s_player{
	t_win		*win;
	t_map		*map;
	int			which_tex;
	double		tox;
	double		toy;
	double		rotangle;
	double		rayangle;
	double		x;
	double		mousex;
	double		mouseang;
	double		y;
	int			map_height;
	int			win_height;
	int			win_width;
	t_img		wind;
	t_img		img_e;
	t_img		img_n;
	t_img		img_w;
	t_img		img_s;
}	t_player;

void	fdda_algorithm(t_player *p);
double	translate_deg_to_rad(double angle);
int		is_wallh(t_player *p, int px, int py);
void	cub3d_game(t_player *p);
t_img	get_wich(t_player *p);
int		get_color(t_img data, int x, int y);
void	my_pixel_put(t_img data, int x, int y, int color);
void	move_player(int key, t_player *p);
void	get_player_info(char **map, t_player *p);
void	fdda_horizontal(t_player *p);
void	fdda_vertical(t_player *p);
void	ft_error(char *error);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*get_next_line_2(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putnbr(int n);
char	**ft_split(char const *s, char c, int *k);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		fcalc_nb(const char *str);

// parser Function
char	*join_and_free(char *save, char *buffer);
char	*move_to_rest(char *stock);
char	*get_line(char *stock);
char	*read_file(int fd, char *save);
char	*fjoin(char *s1, char *s2);
size_t	strchr_newline(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	fcheck_fd(t_game *game);
void	ft_error(char *error);
void	fsetting(t_game *game);
int		collect_element(t_game *game);
void	hndl_collore(t_game *game, int i);
void	hndl_textur(t_game *game, int i);
void	textur_extention(char *str);
void	check_existing(char *str);
void	collect_map(t_game *game, int index);
void	check_map(t_map *map);

// rendering 
void	free_matrix(char **mx);
char	**ft_sp(char *s, char c);
void	rendering_cub3d(t_map *map);

#endif