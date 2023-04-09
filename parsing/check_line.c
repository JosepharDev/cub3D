/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:44:41 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/09 00:14:38 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	texture_line(char *line)
{
	char	**texture;

	texture = ft_split1(line, ' ');
	if (!texture)
		ft_error1("Error\nError in malloc\n", NULL);
	if (len_matrix(texture) != 2)
	{
		if (len_matrix(texture) == 3 && texture[2][0] == '\n')
		{
			free_matrix(texture);
			return (1);
		}
		else
			ft_error1("Error\ninvalid texture", NULL);
	}
	free_matrix(texture);
	return (1);
}

int	check_player(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("EWSN", line[i]))
		{
			if (line[i] && line[i + 1] != '0' && line[i + 1] != '1'
				&& line[i + 1] != ' ')
				ft_error1("Error\nmap is messing\n", NULL);
			if (map->starting_pos)
				return (1);
			map->starting_pos = line[i];
		}
		i++;
	}
	return (0);
}

void	store_map(t_game *game, char *line)
{
	if (!game->map->map)
	{
		game->map->map = malloc(sizeof(char *) * 2);
		game->map->map[0] = ft_strdup(line);
		game->map->map[1] = NULL;
	}
	else
		game->map->map = dup_matrix(game->map->map, line);
}

void	check_line1(t_game *game, char *line)
{
	if ((!game->map->textur->north_texture || !game->map->textur->east_texture \
	|| !game->map->textur->west_texture || !game->map->textur->south_texture \
	|| !game->map->textur->floor || !game->map->textur->ceil) && line[0])
		ft_error1("Error\ninvalid map some texture missing\n", NULL);
	else
	{
		if (check_player(line, game->map) == 1
			&& game->map->starting_pos != '\0')
			ft_error1("duplicated player\n", NULL);
		store_map(game, line);
	}
}

void	check_line(t_game *game, char *line)
{
	if (!white_s(line))
		ft_error1("Error\ninvalid map some invalid white spaces/n", NULL);
	if (is_map(line))
	{
		check_line1(game, line);
	}
	else if (is_texture(line))
	{
		if (!get_texture(game, line))
			ft_error1("Error\nduplicate texture\n", NULL);
	}
	else if (!game->map->textur->north_texture
		|| !game->map->textur->east_texture
		|| !game->map->textur->west_texture || !game->map->textur->south_texture
		|| !game->map->textur->floor || !game->map->textur->ceil)
		ft_error1("Error\ninvalid map some texture missing\n", NULL);
	else
		ft_error1("Error\ninvalid character in map\n", NULL);
}
