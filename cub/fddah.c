/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fddah.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:38:02 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 17:03:12 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	get_hsign(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.signx = 1;
	point.signy = 1;
	if (translate_deg_to_rad(ang) >= 0
		&& translate_deg_to_rad(ang) < M_PI / 2)
	{
		point.x = TZ;
		point.signy = -1;
	}
	else if (translate_deg_to_rad(ang) >= M_PI / 2
		&& translate_deg_to_rad(ang) < M_PI)
	{
		point.signx = -1;
		point.signy = -1;
	}
	else if (translate_deg_to_rad(ang) >= M_PI
		&& translate_deg_to_rad(ang) < 3
		* (M_PI / 2))
		point.signx = -1;
	else
		point.x = TZ;
	return (point);
}

t_point	get_dirh(double ang)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	if (translate_deg_to_rad(ang) >= M_PI / 2
		&& translate_deg_to_rad(ang) < M_PI)
		point.x = -1;
	if (translate_deg_to_rad(ang) >= M_PI
		&& translate_deg_to_rad(ang) < 3
		* (M_PI / 2))
		point.x = -1;
	return (point);
}

int	is_wallh(t_cub *p, int x, int y)
{
	t_point	inc;

	inc = get_dirh(p->rayangle);
	x += inc.x;
	y += inc.y;
	if (!(y < p->map_height / TZ && y >= 0
			&& x < ft_strlen1(p->map->map[y]) && x >= 0))
		return (-1);
	else if (p->map->map[y][x] == '1')
		return (1);
	return (0);
}

void	fdda_hor2(t_cub *p, t_point inc, t_point grid, t_point d)
{
	while (!is_wallh(p, grid.x / TZ, grid.y / TZ))
	{
		grid.x += d.x * inc.signx;
		grid.y += d.y * inc.signy;
		p->tox = grid.x;
		p->toy = grid.y;
	}
	if (is_wallh(p, grid.x / TZ, grid.y / TZ) == 1)
	{
		p->tox = grid.x;
		p->toy = grid.y;
	}
	if (is_wallh(p, grid.x / TZ, grid.y / TZ) == -1)
	{
		p->tox = p->x;
		p->toy = p->y;
	}
}

void	fdda_horizontal(t_cub *p)
{
	t_point	dis_p;
	t_point	increment;
	t_point	grid;

	increment = get_hsign(p->rayangle);
	dis_p.x = TZ;
	grid.x = floor(p->tox / TZ) * TZ + increment.x;
	dis_p.y = fabs(fabs(grid.x - p->x)
			* tan(translate_deg_to_rad(p->rayangle)));
	grid.y = p->toy + (dis_p.y * increment.signy);
	dis_p.y = fabs(TZ * tan(translate_deg_to_rad(p->rayangle)));
	fdda_hor2(p, increment, grid, dis_p);
}
