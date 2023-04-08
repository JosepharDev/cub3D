/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:12 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/07 10:41:55 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid(t_player *p, double x, double y)
{
	if (p->map->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (p->map->map[(int)((y - 3) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (p->map->map[(int)((y + 3) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (p->map->map[(int)(y / TILE_SIZE)][(int)((x - 3) / TILE_SIZE)] == '1')
		return (0);
	if (p->map->map[(int)(y / TILE_SIZE)][(int)((x + 3) / TILE_SIZE)] == '1')
		return (0);
	return (1);
}

void	move_and_rend(t_player *p, double ang)
{
	if (is_valid(p, p->x + cos(translate_deg_to_rad(ang)) * SPEED, p->y
			- sin(translate_deg_to_rad(ang)) * SPEED))
	{
		p->rotangle += p->mouseang;
		p->x += cos(translate_deg_to_rad(ang)) * SPEED;
		p->y -= sin(translate_deg_to_rad(ang)) * SPEED;
		cub3d_game(p);
	}
	else if (p->mouseang != 0)
	{
		p->rotangle += p->mouseang;
		cub3d_game(p);
	}
}

void	move_player(int key, t_player *p)
{
	if (key == UP)
		move_and_rend(p, p->rotangle);
	if (key == DOWN)
		move_and_rend(p, p->rotangle - 180);
	if (key == RIGHT)
		move_and_rend(p, p->rotangle - 90);
	if (key == LEFT)
		move_and_rend(p, p->rotangle + 90);
	if (key == ROTR)
	{
		p->rotangle -= 6;
		cub3d_game(p);
	}
	if (key == ROTL)
	{
		p->rotangle += 6;
		cub3d_game(p);
	}
}
