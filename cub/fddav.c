/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fddav.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:38:16 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:04:23 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	get_dirv(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	if (translate_deg_to_rad(ang) >= 0 && translate_deg_to_rad(ang) < M_PI / 2)
		point.y = -1;
	if (translate_deg_to_rad(ang) >= M_PI / 2
		&& translate_deg_to_rad(ang) < M_PI)
		point.y = -1;
	return (point);
}

t_point	get_vsign(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.signx = 1;
	point.signy = 1;
	if (translate_deg_to_rad(ang) >= 0 && translate_deg_to_rad(ang) < M_PI / 2)
		point.signy = -1;
	else if (translate_deg_to_rad(ang) >= M_PI / 2
		&& translate_deg_to_rad(ang) < M_PI)
	{
		point.signx = -1;
		point.signy = -1;
	}
	else if (translate_deg_to_rad(ang) >= M_PI && translate_deg_to_rad(ang) < 3
		* (M_PI / 2))
	{
		point.signx = -1;
		point.y = TZ;
	}
	else
		point.y = TZ;
	return (point);
}

int	is_wallv(t_cub *p, int px, int py)
{
	t_point	increment;

	increment = get_dirv(p->rayangle);
	px += increment.x;
	py += increment.y;
	if (!(py < p->map_height / TZ && py >= 0 && px < ft_strlen1(p->map->map[py])
			&& px >= 0))
		return (-1);
	else if (p->map->map[py][px] == '1')
		return (1);
	return (0);
}

void	ddav_code(t_cub *p, t_point inc, t_point grid, t_point d)
{
	while (!is_wallv(p, grid.x / TZ, grid.y / TZ))
	{
		grid.x += d.x * inc.signx;
		grid.y += d.y * inc.signy;
		p->tox = grid.x;
		p->toy = grid.y;
	}
	if (is_wallv(p, grid.x / TZ, grid.y / TZ) == 1)
	{
		p->tox = grid.x;
		p->toy = grid.y;
	}
	if (is_wallv(p, grid.x / TZ, grid.y / TZ) == -1)
	{
		p->tox = p->x;
		p->toy = p->y;
	}
}

void	fdda_vertical(t_cub *p)
{
	t_point	distance;
	t_point	grid;
	t_point	increment;

	increment = get_vsign(p->rayangle);
	distance.y = TZ;
	grid.y = floor(p->y / TZ) * TZ + increment.y;
	distance.x = fabs(fabs(p->y - grid.y)
			/ tan(translate_deg_to_rad(p->rayangle)));
	grid.x = p->x + (distance.x * increment.signx);
	distance.x = fabs(TZ / tan(translate_deg_to_rad(p->rayangle)));
	ddav_code(p, increment, grid, distance);
}
