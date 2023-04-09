/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:55:46 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:43:39 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_game *game, char *name)
{
	int	fd;

	init(game);
	fd = is_valid1(name);
	read_file1(game, fd);
	if (!game->map->pos)
		ft_error1("Error\nplayer is mission\n", NULL);
	v_texture(game->map);
	game->map->height = get_height(game->map->map);
	game->map->width = get_mlen(game->map->map);
	valid_map(game->map);
}

void	rendering_cub3d(t_map *map)
{
	t_win	*win;
	t_cub	*p;

	p = malloc(sizeof(t_cub));
	win = malloc(sizeof(t_win));
	linked_cub3d(p, map, win);
	cub3d_game(p);
	hook_cub3d(p, win);
}

void	free_matrix(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
	{
		free(mx[i]);
		i++;
	}
	free(mx);
}

int	main(int argc, char **av)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "ERROR : INVALID NUMBER OF ARGUMENTS\n", 37);
		exit(1);
	}
	parser(&game, av[1]);
	rendering_cub3d(game.map);
	free_matrix(game.map->map);
	return (1);
}
