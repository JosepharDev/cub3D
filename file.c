/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:04:36 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/03 18:06:03 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int keycode, void *p)
{
	t_player	*pl;

	pl = (t_player *)p;
	if (keycode == ESC)
		exit(0);
	// move_player(keycode, pl);
	return (0);
}

void	put_pixels(void *ptr, void *win, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(ptr, win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	rendering_cub2d(t_map *game, t_win *wind, t_player *p)
{
	int	l1;
	int	l2;
	int	x;
	int	y;

	x = 0;
	y = 0;
	l1 = 0;
	l2 = 0;
	while (game->map[l1])
	{
		x = 0;
		l2 = 0;
		printf("\n");
		while (game->map[l1][l2])
		{
			if (game->map[l1][l2] == '1')
				put_pixels(wind->mlxp, wind->mlxw, x, y, 0X000000);
			else if (game->map[l1][l2] == '0')
				put_pixels(wind->mlxp, wind->mlxw, x, y, 0xFFFFFF);
			else if (game->map[l1][l2] == 'W' || game->map[l1][l2] == 'N'
					|| game->map[l1][l2] == 'S' || game->map[l1][l2] == 'E')
			{
				put_pixels(wind->mlxp, wind->mlxw, x, y, 0x0000FF);
			}
			else
				put_pixels(wind->mlxp, wind->mlxw, x, y, 0x00FFFF);
			l2++;
			x += 32;
		}
		printf("%s----", game->map[l1]);
		l1++;
		y += 32;
	}
	mlx_hook(wind->mlxw, 53, 0, exit_game, wind);
	mlx_hook(wind->mlxw, 2, 0, key_hook, p);
	;
	mlx_loop(wind->mlxp);
	// return (wind->mlxp);
}