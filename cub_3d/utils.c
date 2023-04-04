/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:52:47 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/02 15:35:27 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_point	get_hsign(double angle)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.sx = 1;
	point.sy = 1;
	if (translate_deg_to_rad(angle) >= 0 
		&& translate_deg_to_rad(angle) < M_PI
		/ 2)
	{
		point.x = TZ;
		point.sy = -1;
	}
	else if (translate_deg_to_rad(angle) >= M_PI / 2
			&& translate_deg_to_rad(angle) < M_PI)
	{
		point.sx = -1;
		point.sy = -1;
	}
	else if (translate_deg_to_rad(angle) >= M_PI
			&& translate_deg_to_rad(angle) < 3 * (M_PI / 2))
		point.sx = -1;
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
	if (translate_deg_to_rad(ang) >= M_PI && translate_deg_to_rad(ang) < 3
		* (M_PI / 2))
		point.x = -1;
	return (point);
}

int	is_wallh(t_player *p, int x, int y)
{
	t_point	inc;

	inc = get_dirh(p->calc.rayangle);
	x += inc.x;
	y += inc.y;
	if (!(y < p->calc.map_ht / TZ && y >= 0
			&& x < ft_strlen(p->map->map[y]) && x >= 0))
		return (-1);
	else if (p->map->map[y][x] == '1')
		return (1);
	return (0);
}

void	ddah_code(t_player *p, t_point inc, t_point grid, t_point d)
{
	while (!is_wallh(p, grid.x / TZ, grid.y / TZ))
	{
		grid.x += d.x * inc.sx;
		grid.y += d.y * inc.sy;
		p->calc.tox = grid.x;
		p->calc.toy = grid.y;
	}
	if (is_wallh(p, grid.x / TZ, grid.y / TZ) == 1)
	{
		p->calc.tox = grid.x;
		p->calc.toy = grid.y;
	}
	if (is_wallh(p, grid.x / TZ, grid.y / TZ) == -1)
	{
		p->calc.tox = p->calc.x;
		p->calc.toy = p->calc.y;
	}
}
