/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:34:52 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 15:02:56 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	fmouse(int x, int y, void *p)
{
	t_cub	*cub;

	cub = (t_cub *)p;
	if (x > cub->mousex || (x == cub->mousex && x > cub->win_width / 2))
		cub->mouseang = -5;
	else if (x < cub->mousex || x < cub->win_width / 2)
		cub->mouseang = +5;
	else if (y > cub->mousex || (y == cub->mousex && y > cub->win_height / 2))
		cub->mouseang = -5;
	else if (y < cub->mousex || y < cub->win_height / 2)
		cub->mouseang = +5;
	cub->mousex = x;
	cub->mousey = y;
	return (0);
}
