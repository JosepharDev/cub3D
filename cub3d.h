/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:34:27 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/10 20:34:51 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define ESC 53
# define FOV 66.66
# define SPEED 15
# define WIDTH 1500
# define HEIGHT 1200
# define TZ 30

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "getnextline/get_next_line.h"

typedef struct s_textur
{
	char		*no;
	char		*so;
	char		*west_texture;
	char		*east_texture;
	char		*floor;
	char		*ceil;
}				t_textur;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	t_textur	*textur;
	char		pos;
	int			f_c;
	int			c_c;
	t_position	player;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*fd;
	t_map		*map;
}				t_game;

typedef struct s_point
{
	double		x;
	double		signx;
	double		y;
	double		signy;
}				t_point;

typedef struct s_img
{
	void		*img;
	int			w;
	int			h;
	char		*addr;
	char		*dst;
	int			px;
	int			l_len;
	int			endian;
}				t_img;

typedef struct s_win
{
	void		*mlx_p;
	void		*mlx_w;
	void		*img_0;
	void		*img_1;
	void		*img_p;
}				t_win;

typedef struct s_player
{
	t_win		*win;
	t_map		*map;
	int			which_tex;
	double		tox;
	double		toy;
	double		rotangle;
	double		rayangle;
	double		x;
	double		mousey;
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
}				t_cub;

void			init(t_game *game);
int				finish(t_win *win);
int				fkeycode(int keycode, t_cub *pl);
void			linked_cub3d(t_cub	*p, t_map	*map, t_win	*win);
void			hook_cub3d(t_cub	*p, t_win	*win);
int				fmouse(int x, int y, void *p);
void			flinked_xmp_files(t_cub *cub);
void			flinked_address_images(t_cub *cub);
void			fvalid_linked_texture(t_cub *cub);
void			fdda_algorithm(t_cub *p);
double			translate_deg_to_rad(double angle);
int				is_wallh(t_cub *p, int px, int py);
void			cub3d_game(t_cub *p);
t_img			get_wich(t_cub *p);
int				get_color(t_img data, int x, int y);
void			my_pixel_put(t_img data, int x, int y, int color);
void			move_player(int key, t_cub *p);
void			get_player_info(char **map, t_cub *p);
void			fdda_horizontal(t_cub *p);
void			fdda_vertical(t_cub *p);
void			ft_error(char *error);
int				ft_strlen1(char *s);
char			*get_next_line(int fd);
char			*get_next_line_2(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
void			ft_putnbr(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				fcalc_nb(const char *str);
size_t			ft_len(const char *s);
char			*next_line(char *buffer);
char			*new_line(char *buffer);
char			*filread(int fd, char *buffer);
char			*gcl(int fd);
size_t			strchr_newline(char *str);
char			*ft_strcat(char *pdf, char *dest, char *src);
char			*ft_join(char *s1, char *s2);
char			*ft_sub(char const *s, unsigned int start, size_t len);
void			free_matrix(char **mx);
char			**ft_sp(char *s, char c);
void			rendering_cub3d(t_map *map);

// parser Function
char			*join_and_free(char *save, char *buffer);
char			*move_to_rest(char *stock);
char			*get_line(char *stock);
char			*read_file(int fd, char *save);
char			*fjoin(char *s1, char *s2);
size_t			strchr_newline(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			fcheck_fd(t_game *game);
void			ft_error(char *error);
void			fsetting(t_game *game);
int				collect_element(t_game *game);
void			hndl_collore(t_game *game, int i);
void			hndl_textur(t_game *game, int i);
void			textur_extention(char *str);
void			check_existing(char *str);
void			collect_map(t_game *game, int index);
void			check_map(t_map *map);

// rendering

//////////  error ///////
void			ft_error1(char *str, char *fre);

///////		utils /////////
void			move_and_rend(t_cub *p, double ang);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_strlen(const char *s);
void			line_del(t_map *map);
int				ft_atoi(char *str);
void			free_matrix(char **mx);
char			*ft_substr1(char *s, unsigned int start, size_t len);
char			**ft_split1(char *s, char c);
char			*ft_strdup1(char *s1);
char			*ft_strjoin1(char *s1, char *s2);
int				ft_isalpha1(char c);
int				ft_isdigit1(char c);
int				get_mlen(char **str);
int				get_height(char **str);
void			map_withspace(t_map *map);
void			parser(t_game *game, char *name);
int				is_map(char *line);
int				white_s(char *line);
int				is_valid1(char *arg);
int				check_name(char *name);
char			*get_last(char *name);
int				read_file1(t_game *game, int fd);
void			store_map(t_game *game, char *line);
void			check_line(t_game *game, char *line);
int				get_texture(t_game *game, char *line);
int				len_matrix(char **arr);
char			**dup_matrix(char **arr, char *line);
int				is_texture(char *line);
void			rgb_f(t_map *map);
void			rgb_c(t_map *map);
void			v_texture(t_map *map);
void			valid_map(t_map *map);
void			get_player(t_map *map);
int				texture_line(char *line);
#endif