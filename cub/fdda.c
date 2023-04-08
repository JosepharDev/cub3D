/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdda.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:37:35 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 13:22:55 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_dis(double stx, double sty, double endx, double endy)
{
	double	start_pow;
	double	end_pow;
	double	calc_sqrt;

	start_pow = pow(endx - stx, 2);
	end_pow = pow(endy - sty, 2);
	calc_sqrt = sqrt(start_pow + end_pow);
	return (sqrt(pow(endx - stx, 2) + pow(endy - sty, 2)));
}

void	fsin_direction(t_player *p)
{
	double	calc_sin;

	calc_sin = sin(translate_deg_to_rad(p->rayangle));
	if (calc_sin > 0)
		p->which_tex = 'N';
	else
		p->which_tex = 'S';
}

void	fcos_direction(t_player *p, t_point	hor)
{
	double	calc_cos;

	calc_cos = cos(translate_deg_to_rad(p->rayangle));
	if (calc_cos > 0)
		p->which_tex = 'E';
	else
		p->which_tex = 'W';
	p->tox = hor.x;
	p->toy = hor.y;
}

void	check_wich(t_player *p, double dish, double disv, t_point hor)
{
	if (((dish > disv) && disv != 0) || dish == 0)
		fsin_direction(p);
	else
		fcos_direction(p, hor);
}

void	fdda_algorithm(t_player *p)
{
	t_point	hor;
	double	dis_horizontal;
	double	dis_vertical;

	fdda_horizontal(p);
	hor.x = p->tox;
	hor.y = p->toy;
	fdda_vertical(p);
	dis_horizontal = get_dis(p->x, p->y, hor.x, hor.y);
	dis_vertical = get_dis(p->x, p->y, p->tox, p->toy);
	check_wich(p, dis_horizontal, dis_vertical, hor);
}
