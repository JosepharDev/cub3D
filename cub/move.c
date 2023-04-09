/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:40:12 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:04:37 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid(t_cub *p, double x, double y)
{
	if (p->map->map[(int)(y / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (p->map->map[(int)((y - 3) / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (p->map->map[(int)((y + 3) / TZ)][(int)(x / TZ)] == '1')
		return (0);
	if (p->map->map[(int)(y / TZ)][(int)((x - 3) / TZ)] == '1')
		return (0);
	if (p->map->map[(int)(y / TZ)][(int)((x + 3) / TZ)] == '1')
		return (0);
	return (1);
}

void	move_and_rend(t_cub *p, double ang)
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
