/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:16 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/05 14:07:57 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H



# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "getnextline/get_next_line.h"

# define KEY_EXIT	17
# define ESC		53
# define TZ			30
# define WIDTH		70
# define HEIGHT		30
# define FOV		66
# define WHITE		70
# define HEIGHT		30


typedef struct s_textur
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceil;
}				t_textur;

typedef struct s_position
{
	int	px;
	int	py;
}				t_position;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	char		start_p;
	int			floor_c;
	int			ceil_c;
	t_textur	*textur;
	t_position	player;
}				t_map;

typedef struct s_point
{
	double	x;
	double	sx;
	double	y;
	double	sy;
}			t_point;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
	char	*addr;
	char	*dst;
	int		pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_win
{
	void	*mlxp;
	void	*mlxw;
	void	*img_0;
	void	*img_1;
	void	*img_p;
}			t_win;

typedef	struct s_calcul
{
	int			wtex;
	double		tox;
	double		toy;
	double		rotangle;
	double		rayangle;
	double		x;
	double		mousex;
	double		mouse_ang;
	double		y;
	int			map_ht;
	int			win_ht;
	int			win_wh;
}				t_calcul;

typedef struct s_player
{
	t_win		*win;
	t_map		*map;
	t_calcul	calc;	
	t_img		wind;
	t_img		*img_e;
	t_img		*img_n;
	t_img		*img_w;
	t_img		*img_s;
}				t_player;


typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		size;
	char	*fd_name;
	t_map	*map;
}				t_game;



// CUB3D---------------->REY-CASTING:
t_point	get_dirv(double ang);
t_point	get_dirh(double ang);
t_point	get_vsign(double ang);
t_img	*get_wich(t_player *p);
t_point	get_hsign(double angle);
void	fcub3d_game(t_player *p);
void	fdda_vertical(t_player *p);
void	fdda_algorithm(t_player *p);
void    file_texture(t_player   *p);
void	fdda_horizontal(t_player *p);
void    flinked_data_addr(t_player  *pr);
double	translate_deg_to_rad(double angle);
void	fplayer(char	**map, t_player *p);
int		is_wallv(t_player *p, int x, int y);
int		is_wallh(t_player *p, int x, int y);
void    fcheck_valid_texture(t_player   *p);
int		fvalid_mouve(t_player *p, double x, double y);
void	my_pixel_put(t_img data, int x, int y, int color);
void	fcheck_position(t_player *p, int c, int i, int j);
void	draw(t_player *p, double wallh, double dis, int i);
int		get_color(t_img *data, int x, int y, t_player	*p);
int		draw_line(t_point fr, double toy, int color, t_img p_img);
double	get_dis(double stx, double sty, double endx, double endy);
void	ddah_code(t_player *p, t_point inc, t_point grid, t_point d);
void	check_wich(t_player *p, double dish, double disv, t_point hor);
int		draw_texture(t_point fr, t_img p_img, t_player *p, double wallh);
void	ddav_code(t_player *p, t_point increment, t_point grid, t_point d);

// CUB3D--------------->PARSING:
void	rgb_f(t_map *map);
void	rgb_c(t_map *map);
void	init(t_game *game);
int		is_map(char *line);
int		white_s(char *line);
int		is_valid(char *arg);
void	line_del(t_map *map);
int		get_mlen(char **str);
int		get_height(char **str);
char	*get_last(char *name);
void	v_texture(t_map *map);
void	valid_map(t_map *map);
void	free_matrix(char **mx);
int		check_name(char *name);
void	get_player(t_map *map);
int		len_matrix(char **arr);
int		is_texture(char *line);
void	map_withspace(t_map *map);
void	ft_error(char *str, char *fre);
int		read_file(t_game *game, int fd);
void	parser(t_game *game, char *name);
void	store_map(t_game *game, char *line);
void	check_line(t_game *game, char *line);
char	**dup_matrix(char **arr, char *line);
int		get_texture(t_game *game, char *line);

// CUB3D--------------->PARSING---UTILS:
int		ft_isalpha(char c);
int		ft_isdigit(char c);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
void	ft_error(char *str, char *fre);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif