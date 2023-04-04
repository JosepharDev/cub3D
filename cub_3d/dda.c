/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:44:51 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/04 11:19:09 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	fsin_direction(t_player *p)
{
	double	calc_sin;

	calc_sin = sin(translate_deg_to_rad(p->calc.rayangle));
	if (calc_sin > 0)
		p->calc.wtex = 'N';
	else
		p->calc.wtex = 'S';
}

void	fcos_direction(t_player *p, t_point	hor)
{
	double	calc_cos;

	calc_cos = cos(translate_deg_to_rad(p->calc.rayangle));
	if (calc_cos > 0)
		p->calc.wtex = 'E';
	else
		p->calc.wtex = 'W';
	p->calc.tox = hor.x;
	p->calc.toy = hor.y;
}

void	check_wich(t_player *p, double dish, double disv, t_point hor)
{
	if (((dish > disv) && disv != 0) || dish == 0)
		fsin_direction(p);
	else
		fcos_direction(p, hor);
}

double	get_dis(double stx, double sty, double endx, double endy)
{
	double start_pow;
	double end_pow;
	double calc_sqrt;

	start_pow = pow(endx - stx, 2);
	end_pow = pow(endy - sty, 2);
	calc_sqrt = sqrt(start_pow + end_pow);
	return (calc_sqrt);
}

void	fdda_vertical(t_player *p)
{
	t_point	d;
	t_point	grid;
	t_point	inc;
	double	calc_tan;

	calc_tan = tan(translate_deg_to_rad(p->calc.rayangle));
	inc = get_vsign(p->calc.rayangle);
	d.y = TZ;
	grid.y = floor(p->calc.y / TZ) * TZ + inc.y;
	d.x = fabs(fabs(p->calc.y - grid.y) / calc_tan);
	grid.x = p->calc.x + (d.x * inc.sx);
	d.x = fabs(TZ / calc_tan);
	ddav_code(p, inc, grid, d);
}

void	fdda_horizontal(t_player *p)
{
	t_point	d;
	t_point	inc;
	t_point	grid;

	inc = get_hsign(p->calc.rayangle);
	d.x = TZ;
	grid.x = floor(p->calc.tox / TZ) * TZ + inc.x;
	d.y = fabs(fabs(grid.x - p->calc.x)
			* tan(translate_deg_to_rad(p->calc.rayangle)));
	grid.y = p->calc.toy + (d.y * inc.sy);
	d.y = fabs(TZ * tan(translate_deg_to_rad(p->calc.rayangle)));
	ddah_code(p, inc, grid, d);
}
