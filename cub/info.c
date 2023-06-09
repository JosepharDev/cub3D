/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:38:30 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 17:03:12 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player_pos(t_cub *p, int c, int i, int j)
{
	if (c == 'E')
		p->rotangle = 0;
	if (c == 'N')
		p->rotangle = 90;
	if (c == 'W')
		p->rotangle = 180;
	if (c == 'S')
		p->rotangle = 270;
	p->x = (j * TZ) + TZ / 2;
	p->y = (i * TZ) + TZ / 2;
	p->tox = p->x;
	p->toy = p->y;
}

void	get_player_info(char **map, t_cub *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S')
				get_player_pos(p, map[i][j], i, j);
			j++;
		}
		i++;
	}
	p->map_height = i * TZ;
}
