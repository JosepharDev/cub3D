/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:34:08 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/08 22:36:49 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'S' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player.x = i;
				map->player.y = j;
				return ;
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
	game->map->textur->east_texture = NULL;
	game->map->textur->floor = NULL;
	game->map->textur->north_texture = NULL;
	game->map->textur->south_texture = NULL;
	game->map->textur->west_texture = NULL;
	game->map->map = NULL;
	game->map->starting_pos = '\0';
}

void	parser(t_game *game, char *name)
{
	int	fd;

	init(game);
	fd = is_valid1(name);
	read_file1(game, fd);
	if (!game->map->starting_pos)
		ft_error1("Error\nplayer is mission\n", NULL);
	v_texture(game->map);
	game->map->height = get_height(game->map->map);
	game->map->width = get_mlen(game->map->map);
	valid_map(game->map);
}
