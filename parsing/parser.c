/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:34:08 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/04 22:23:40 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == 'S' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player.px = i;
				map->player.py = j;
				return;
			}
			j++;
		}
		i++;
	}
}

void	init(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	game->map->textur = malloc(sizeof(t_textur));
	game->map->textur->ceil = NULL;
	game->map->textur->ea = NULL;
	game->map->textur->floor = NULL;
	game->map->textur->no = NULL;
	game->map->textur->so = NULL;
	game->map->textur->we = NULL;
	game->map->map = NULL;
	game->map->start_p = '\0';
}
