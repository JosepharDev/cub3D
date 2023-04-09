/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:35 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:38:41 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	finish(t_win *win)
{
	mlx_destroy_window(win->mlx_p, win->mlx_w);
	exit(0);
}

int	fkeycode(int keycode, t_cub *pl)
{
	if (keycode == ESC)
		finish(pl->win);
	if (keycode == 13)
		move_and_rend(pl, pl->rotangle);
	if (keycode == 1)
		move_and_rend(pl, pl->rotangle - 180);
	if (keycode == 2)
		move_and_rend(pl, pl->rotangle - 90);
	if (keycode == 0)
		move_and_rend(pl, pl->rotangle + 90);
	if (keycode == 124)
	{
		pl->rotangle -= 6;
		cub3d_game(pl);
	}
	if (keycode == 123)
	{
		pl->rotangle += 6;
		cub3d_game(pl);
	}
	pl->mouseang = 0;
	return (0);
}

void	linked_cub3d(t_cub	*p, t_map	*map, t_win	*win)
{
	win->mlx_p = mlx_init();
	p->win = win;
	p->map = map;
	fvalid_linked_texture(p);
	get_player_info(map->map, p);
	p->win_width = 60 * TZ;
	p->win_height = 30 * TZ;
	win->mlx_w = mlx_new_window(win->mlx_p, p->win_width, p->win_height,
			"CUB3D");
	p->wind.img = mlx_new_image(p->win->mlx_p, p->win_width, p->win_height);
	p->wind.addr = mlx_get_data_addr(p->wind.img, &(p->wind.px),
			&(p->wind.l_len), &(p->wind.endian));
}

void	hook_cub3d(t_cub	*p, t_win	*win)
{
	mlx_hook(win->mlx_w, 17, 0, finish, win);
	p->mouseang = 0;
	mlx_hook(win->mlx_w, 6, 0, fmouse, p);
	mlx_hook(win->mlx_w, 2, 0, fkeycode, p);
	p->mousex = 0;
	p->mousey = 0;
	mlx_loop(win->mlx_p);
}
