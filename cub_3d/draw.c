/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:56:31 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/05 17:10:41 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	get_color(t_img *data, int x, int y, t_player	*p)
{
	char		*dst;

	if (x < 0 || x >= p->calc.win_ht || y < 0 || y >= p->calc.win_wh)
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->pixel/ 8));
	return (*(unsigned int *) dst);
}

void	my_pixel_put(t_img data, int x, int y, int *color)
{
	t_player	*p;
	char		*dst;

	p = malloc(sizeof(t_player));
	if (x < 0 || x >= p->calc.win_ht || y < 0 || y >= p->calc.win_wh)
		return ;
	printf("%d--lllllllll----\n", p->calc.win_ht);
	dst = data.addr + (y * data.line_length + x * (data.pixel / 8));
	*color = *(unsigned int *)dst;
	printf("++++++%d-----\n", *color);
	// *(unsigned int *) dst = color;
	free(p);
}

t_img	*get_wich(t_player *p)
{
	t_img	*direction;
	
	direction = NULL;
	// if (p->calc.wtex == 'E')
	// {
	// 	printf("eeee\n");
	// 	direction = p->img_e->img;
	// 	return (direction);
	// }
	// 	// return (p->img_e);
	// if (p->calc.wtex == 'N')
	// {
	// 	printf("nnn\n");
	// 	direction = p->img_n->img;
	// 	return (direction);
	// }
	// 	// return (p->img_n);
	// if (p->calc.wtex == 'W')
	// {
		// printf("WWWW\n");
		// printf("-----hello----\n");
		direction = p->img_w->img;
		return (direction);
	// }
	// 	// return (p->img_w);
	// if (p->calc.wtex == 'S')
	// {
	// 	printf("SSSS\n");
	// 	// printf("llop-----\n");
	// 	direction = p->img_s->img;
	// 	return (direction);
	// }
	// // printf("%d---\n", p->calc.wtex);
	// return (direction);
}

int	draw_line(t_point fr, double toy, int color, t_img p_img)
{	
	while (fr.y < toy)
	{
		my_pixel_put(p_img, fr.x, fr.y, &color);
		(fr.y)++;
	}
	return (0);
}

int	draw_texture(t_point fr, t_img p_img, t_player *p, double wallh)
{
	t_img	*img;
	double	newy;
	double	inc;
	int		color;

	img = get_wich(p);
	newy = 0;
	inc = img->h / (2 * wallh);
	p->calc.tox = floor((int)(img->w * ((p->calc.tox + p->calc.toy) / TZ)) % img->w);
	if ((2 * wallh) > p->calc.win_ht)
		newy = (int)((((2 * wallh) - p->calc.win_ht) / 2) * inc) % img->h;
	p->calc.toy = p->calc.win_ht - fr.y;
	while (fr.y < p->calc.toy)
	{
		color = get_color(img, p->calc.tox, newy, p);
		// printf("++++%d----\n", color);

		my_pixel_put(p_img, fr.x, fr.y, &color);
		// printf("++++%d----\n", color);
		(fr.y)++;
		newy += inc;
		if (newy > img->h)
			newy = (int)newy % img->h;
	}
	return (0);
}
