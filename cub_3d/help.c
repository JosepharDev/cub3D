/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:29:42 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/02 15:36:24 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_point	get_vsign(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.sx = 1;
	point.sy = 1;
	if (translate_deg_to_rad(ang) >= 0 
		&& translate_deg_to_rad(ang) < M_PI / 2)
		point.sy = -1;
	else if (translate_deg_to_rad(ang) >= M_PI / 2
			&& translate_deg_to_rad(ang) < M_PI)
	{
		point.sx = -1;
		point.sy = -1;
	}
	else if (translate_deg_to_rad(ang) >= M_PI 
		&& translate_deg_to_rad(ang) < 3
			* (M_PI / 2))
	{
		point.sx = -1;
		point.y = TZ;
	}
	else
		point.y = TZ;
	return (point);
}

t_point	get_dirv(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	if (translate_deg_to_rad(ang) >= 0 
		&& translate_deg_to_rad(ang) < M_PI / 2)
		point.y = -1;
	if (translate_deg_to_rad(ang) >= M_PI / 2 
		&& translate_deg_to_rad(ang) < M_PI)
		point.y = -1;
	return (point);
}

int	is_wallv(t_player *p, int x, int y)
{
	t_point	increment;

	increment = get_dirv(p->calc.rayangle);
	x += increment.x;
	y += increment.y;
	if (!(y < p->calc.map_ht/ TZ && y >= 0 \
		&& x < ft_strlen(p->map->map[y]) && x >= 0))
		return (-1);
	else if (p->map->map[y][x] == '1')
		return (1);
	return (0);
}

void	ddav_code(t_player *p, t_point increment, t_point grid, t_point d)
{
	while (!is_wallv(p, grid.x / TZ, grid.y / TZ))
	{
		grid.x += d.x * increment.sx;
		grid.y += d.y * increment.sy;
		p->calc.tox = grid.x;
		p->calc.toy = grid.y;
	}
	if (is_wallv(p, grid.x / TZ, grid.y / TZ) == 1)
	{
		p->calc.tox = grid.x;
		p->calc.toy = grid.y;
	}
	if (is_wallv(p, grid.x / TZ, grid.y / TZ) == -1)
	{
		p->calc.tox = p->calc.x;
		p->calc.toy = p->calc.y;
	}
}
