/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:41:09 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 14:19:54 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_line(t_point fr, double toy, int color, t_img p_img)
{	
	while (fr.y < toy)
	{
		my_pixel_put(p_img, fr.x, fr.y, color);
		(fr.y)++;
	}
	return (0);
}

int	draw_texture(t_point fr, t_img p_img, t_player *p, double wallh)
{
	t_img	img;
	double	newy;
	double	inc;
	int		color;

	img = get_wich(p);
	newy = 0;
	inc = img.h / (2 * wallh);
	p->tox = floor((int)(img.w * ((p->tox + p->toy) / TILE_SIZE)) % img.w);
	if ((2 * wallh) > p->win_height)
		newy = (int)((((2 * wallh) - p->win_height) / 2) * inc) % img.h;
	p->toy = p->win_height - fr.y;
	while (fr.y < p->toy)
	{
		color = get_color(img, p->tox, newy);
		my_pixel_put(p_img, fr.x, fr.y, color);
		(fr.y)++;
		newy += inc;
		if (newy > img.h)
			newy = (int)newy % img.h;
	}
	return (0);
}

void	draw(t_player *p, double wallh, double dis, int i)
{
	t_point	from;

	from.x = i;
	from.y = 0;
	draw_line(from, (p->win_height / 2) \
		- wallh, p->map->ceilling_color, p->wind);
	from.y = (p->win_height / 2) - wallh;
	draw_texture(from, p->wind, p, \
		roundf((p->win_height / dis) * TILE_SIZE));
	from.y = (p->win_height / 2) + wallh;
	draw_line(from, p->win_height - 1, p->map->floor_color, p->wind);
}

void	cub3d_game(t_player *p)
{
	double	distance;
	double	wall_height;
	int		l1;

	p->rayangle = p->rotangle + (FOV / 2);
	l1 = 0;
	while (l1 < p->win_width)
	{
		p->tox = p->x;
		p->toy = p->y;
		fdda_algorithm(p);
		distance = sqrt(pow(p->x - p->tox, 2.0) + pow(p->y - p->toy, 2.0));
		distance = distance * cos(translate_deg_to_rad(p->rayangle - p->rotangle));
		wall_height = roundf(((p->win_height) / distance) * TILE_SIZE);
		if (wall_height > p->win_height / 2)
			wall_height = p->win_height / 2;
		draw(p, wall_height, distance, l1);
		p->rayangle -= FOV / p->win_width;
		l1++;
	}
	mlx_put_image_to_window(p->win->mlx_p, p->win->mlx_w, p->wind.img, 0, 0);
}
