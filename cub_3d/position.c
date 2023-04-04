/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:11:08 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/04 11:06:13 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	fcheck_position(t_player *p, int c, int i, int l2)
{
	if (c == 'E')
		p->calc.rotangle = 0;
	if (c == 'N')
		p->calc.rotangle = 90;
	if (c == 'W')
		p->calc.rotangle = 180;
	if (c == 'S')
		p->calc.rotangle = 270;
	p->calc.x = (l2 * TZ) + TZ / 2;
	p->calc.y = (i * TZ) + TZ / 2;
	p->calc.tox = p->calc.x;
	p->calc.toy = p->calc.y;
}

void	fplayer(char	**map, t_player *p)
{
	int	l1;
	int	l2;

	l1 = 0;
	p->calc.map_ht = 0;
	while (map[l1])
	{
		l2 = 0;
		while (map[l1][l2])
		{
			if (map[l1][l2] == 'N' || map[l1][l2] == 'W'
				|| map[l1][l2] == 'E' || map[l1][l2] == 'S')
				fcheck_position(p, map[l1][l2], l1, l2);
			l2++;
		}
		l1++;
	}
	printf("variable 12 : ---> %d---\n", p->calc.map_ht);
	p->calc.map_ht = l1 * TZ;
}
