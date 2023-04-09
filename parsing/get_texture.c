/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:36:27 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/09 15:38:46 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture2(t_game *game, char *line, int len, int i)
{
	if (ft_strncmp(&line[i], "WE ", 3) == 0 && len > 3 && texture_line(line))
	{
		if (game->map->textur->west_texture)
			return (0);
		game->map->textur->west_texture = ft_strdup(line + 3);
	}
	else if (ft_strncmp(&line[i], "EA ", 3) == 0 && len > 3
		&& texture_line(line))
	{
		if (game->map->textur->east_texture && texture_line(line))
			return (0);
		game->map->textur->east_texture = ft_strdup(line + 3);
	}
	return (1);
}

int	get_texture1(t_game *game, char *line, int len, int i)
{
	if (ft_strncmp(&line[i], "NO ", 3) == 0 && len > 3 && texture_line(line))
	{
		if (game->map->textur->no)
			return (0);
		game->map->textur->no = ft_strdup(line + 3);
	}
	else if (ft_strncmp(&line[i], "SO ", 3) == 0 && len > 3
		&& texture_line(line))
	{
		if (game->map->textur->so)
			return (0);
		game->map->textur->so = ft_strdup(line + 3);
	}
	return (get_texture2(game, line, len, i));
}

int	get_texture(t_game *game, char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	len = ft_strlen1(&line[i]);
	if (ft_strncmp(&line[i], "C ", 2) == 0 && len > 3)
	{
		if (game->map->textur->ceil)
			return (0);
		game->map->textur->ceil = ft_strdup1(&line[i + 2]);
	}
	else if (ft_strncmp(&line[i], "F ", 2) == 0 && len > 3)
	{
		if (game->map->textur->floor)
			return (0);
		game->map->textur->floor = ft_strdup1(&line[i + 2]);
	}
	return (get_texture1(game, line, len, i));
}
