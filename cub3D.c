/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:35:18 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/04 19:58:43 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_game(t_win *win)
{
	mlx_destroy_window(win->mlxp, win->mlxw);
	exit(0);
}

int	fmouse(int x, int y, void *p)
{
	t_player	*pl;

	pl = (t_player *)p;
	(void)y;
	
	if (x > pl->calc.mousex || (x == pl->calc.mousex 
		&& x > pl->calc.win_wh / 2))
		pl->calc.mouse_ang -= 5;
	else
		pl->calc.mouse_ang += 5;
	pl->calc.mousex = x;
	return (0);
}

void	parser(t_game *game, char *name)
{
	int	fd;

	init(game); 
	fd = is_valid(name);
	read_file(game, fd);
	if (!game->map->start_p)
		ft_error("Error\nplayer is mission\n", NULL);
	v_texture(game->map);
	game->map->height = get_height(game->map->map);
	game->map->width = get_mlen(game->map->map);
	valid_map(game->map);
}

int	fvalid_mouve(t_player *cub, double x, double y)
{
	if (cub->map->map[(int)(y / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (cub->map->map[(int)((y - 3) / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (cub->map->map[(int)((y + 3) / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (cub->map->map[(int)(y / TZ)][(int)((x - 3) / TZ)] == '1')
		return (0);
	if (cub->map->map[(int)(y / TZ)][(int)((x + 3) / TZ)] == '1')
		return (0);
	return (1);
}

void	fmove(t_player *player, double angle)
{
	int		speed;
	double	c;
	double	s;
	double	l1;
	double	l2;

	speed = 5;
	c = cos(translate_deg_to_rad(angle));
	s = sin(translate_deg_to_rad(angle));
	l1 = player->calc.x + c * speed;
	l2 = player->calc.y - s * speed;
	if (fvalid_mouve(player, l1, l2))
	{
		player->calc.rotangle += player->calc.mouse_ang;
		player->calc.x += c * speed;
		player->calc.y -= s * speed;
		fcub3d_game(player);
	}
	else if (player->calc.mouse_ang != 0)
	{
		player->calc.rotangle += player->calc.mouse_ang;
		fcub3d_game(player);
	}
}

int	fkey(int key, t_player *mouvement)
{
	double	calcul;

	calcul = mouvement->calc.rotangle;
	if (key == 53)
		exit_game(mouvement->win);
	if (key == 13)
		fmove(mouvement, calcul);
	if (key == 0)
		fmove(mouvement, calcul - 180);
	if (key == 1)
		fmove(mouvement, calcul - 90);
	if (key == 2)
		fmove(mouvement, calcul + 90);
	if (key == 124)
	{
		calcul -= 6;
		fcub3d_game(mouvement);
	}
	if (key == 123)
	{
		calcul += 6;
		fcub3d_game(mouvement);
	}
	mouvement->calc.mouse_ang = 0;
	return (0);
}

void	rendering_cub3d(t_map *game)
{
	t_player	*p;
	t_win		*wind;

	p = malloc(sizeof(t_player));
	wind = malloc(sizeof(t_win));
	wind->mlxp = mlx_init();
	p->win = wind;
	p->map = game;
	// fcheck_valid_texture(p);
	file_texture(p);
	fplayer(game->map, p);
	p->calc.win_wh = WHITE * TZ;
	p->calc.win_ht = HEIGHT * TZ;
	printf("%d-----\n", p->calc.win_wh);
	printf("%d-----\n", p->calc.win_ht);
	printf("--%d\n", game->player.px);
	printf("--%d\n", game->player.py);
	printf("-%c\n", game->start_p);
	wind->mlxw = mlx_new_window(wind->mlxp, p->calc.win_wh, p->calc.win_ht, "CUB3D");
	p->wind.img = mlx_new_image(p->win->mlxp, p->calc.win_wh, p->calc.win_ht);
	p->wind.addr = mlx_get_data_addr(p->wind.img, &(p->wind.pixel),
			&(p->wind.line_length), &(p->wind.endian));
	fcub3d_game(p);
	mlx_hook(wind->mlxw, KEY_EXIT, 0, exit_game, wind);
	p->calc.mouse_ang = 0;
	mlx_hook(wind->mlxw, 6, 0, fmouse, p);
	mlx_hook(wind->mlxw, 2, 0, fkey, p);
	p->calc.mousex = 0;
	mlx_loop(wind->mlxp);
	// free(wind);
	// free(p);
	//wind->mlxw = mlx_new_window(wind->mlxp, game->width * 20, game->height
			// * 20, "Cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;

	// game = malloc(sizeof(t_game));
	if (argc != 2)
		ft_error("Error\nnumber of arg not valid\n", NULL);
	parser(&game, argv[1]);
	rendering_cub3d(game.map);
	// printf("\n");
	// printf("--%d\n", game.map->player.px);
	// printf("--%d\n", game.map->player.py);
	// printf("-%c\n", game.map->start_p);
	return (1);
}
