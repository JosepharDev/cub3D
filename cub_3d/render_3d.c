/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:34:55 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/02 15:33:33 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

double	translate_deg_to_rad(double angle)
{
	while (angle > 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	return (angle * M_PI / 180);
}

void	draw(t_player *p, double wallh, double dis, int i)
{
	t_point	from;

	from.x = i;
	from.y = 0;
	draw_line(from, (p->calc.win_ht / 2) \
		- wallh, p->map->ceil_c, p->wind);
	from.y = (p->calc.win_ht / 2) - wallh;
	draw_texture(from, p->wind, p, \
		roundf((p->calc.win_ht / dis) * TZ));
	from.y = (p->calc.win_ht / 2) + wallh;
	draw_line(from, p->calc.win_ht - 1, p->map->floor_c, p->wind);
}

void	fdda_algorithm(t_player *p)
{
	t_point	hor;
	double	dish;
	double	disv;

	fdda_horizontal(p);
	hor.x = p->calc.tox;
	hor.y = p->calc.toy;
	fdda_vertical(p);
	dish = get_dis(p->calc.x, p->calc.y, hor.x, hor.y);
	disv = get_dis(p->calc.x, p->calc.y, p->calc.tox, p->calc.toy);
	check_wich(p, dish, disv, hor);
}

void	fcub3d_game(t_player *p)
{
	double dis;
	double wallh;
	int i;

	p->calc.rayangle = p->calc.rotangle + (FOV / 2);
	i = 0;
	while (i < p->calc.win_wh)
	{
		p->calc.tox = p->calc.x;
		p->calc.toy = p->calc.y;
		fdda_algorithm(p);
		dis = sqrt(pow(p->calc.x - p->calc.tox, 2.0) 
                + pow(p->calc.y - p->calc.toy, 2.0));
		dis = dis * cos(translate_deg_to_rad(p->calc.rayangle
					- p->calc.rotangle));
		wallh = roundf(((p->calc.win_ht) / dis) * TZ);
		if (wallh > p->calc.win_ht / 2)
			wallh = p->calc.win_ht / 2;
		draw(p, wallh, dis, i);
		p->calc.rayangle -= FOV / p->calc.win_wh;
		i++;
	}
	mlx_put_image_to_window(p->win->mlxp, p->win->mlxw, p->wind.img, 0, 0);
}
