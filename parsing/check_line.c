/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:44:41 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/19 09:59:11 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (strchr("EWSN", line[i]))
		{
			if (map->start_p)
				return (1);
			map->start_p = line[i];
		}
		i++;
	}
	return (0);
}

void	store_map(t_game *game, char *line)
{
	int	len;

	if (!game->map->map)
	{
		game->map->map = malloc(sizeof(char *) * 2);
		game->map->map[0] = ft_strdup(line);
		game->map->map[1] = NULL;
	}
	else
		game->map->map = dup_matrix(game->map->map, line);
}

// void	check_line1(t_game *game, char *line)
// {
// 	else if (is_texture(line))
// 	{
// 		if (!get_texture(game, line))
// 			ft_error("Error\nduplicate texture\n", NULL);
// 	}
// 	else if (!game->map->textur->no || !game->map->textur->ea
// 		|| !game->map->textur->we || !game->map->textur->so
// 		|| !game->map->textur->floor || !game->map->textur->ceil)
// 		ft_error("Error\ninvalid map some texture missing\n", NULL);
// 	else
// 		ft_error("Error\ninvalid character in map\n", NULL);
// }

void	check_line(t_game *game, char *line)
{
	if (!white_s(line))
		ft_error("Error\ninvalid map some invalid white spaces/n", NULL);
	if (is_map(line))
	{
		if (!game->map->textur->no || !game->map->textur->ea
			|| !game->map->textur->we || !game->map->textur->so
			|| !game->map->textur->floor || !game->map->textur->ceil)
			ft_error("Error\ninvalid map some texture missing/n", NULL);
		else
		{
			if (check_player(line, game->map) == 1
				&& game->map->start_p != '\0')
				ft_error("duplicated player\n", NULL);
			store_map(game, line);
		}
	}
	else if (is_texture(line))
	{
		if (!get_texture(game, line))
			ft_error("Error\nduplicate texture\n", NULL);
	}
	else if (!game->map->textur->no || !game->map->textur->ea
		|| !game->map->textur->we || !game->map->textur->so
		|| !game->map->textur->floor || !game->map->textur->ceil)
		ft_error("Error\ninvalid map some texture missing\n", NULL);
	else
		ft_error("Error\ninvalid character in map\n", NULL);
	// check_line1(game, line);
}
