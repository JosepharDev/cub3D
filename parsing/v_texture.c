/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:36:27 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/19 09:59:46 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_path(char *line)
{
	int		i;
	int		len;
	int		j;
	char	*path;
	int		fd;

	i = 0;
	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		ft_error("Error\ntexture path messing\n", NULL);
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\n')
		j++;
	path = ft_substr(line, i, j - i);
	len = ft_strlen(path);
	if (len >= 5 && strncmp(&path[len - 4], ".xpm", 4) == 0)
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			ft_error("Error\ncan't reload invalid PATH\n", path);
		close(fd);
	}
	else
		ft_error("Error\npath should include .xmp\n", path);
	free(path);
}

int	is_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (0);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (1);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		return (1);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		return (1);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		return (1);
	return (0);
}

int	get_texture1(t_game *game, char *line, int len, int i)
{
	if (strncmp(&line[i], "NO ", 3) == 0 && len > 3)
	{
		if (game->map->textur->no)
			return (0);
		game->map->textur->no = ft_strdup(line + 3);
	}
	else if (strncmp(&line[i], "SO ", 3) == 0 && len > 3)
	{
		if (game->map->textur->so)
			return (0);
		game->map->textur->so = ft_strdup(line + 3);
	}
	else if (strncmp(&line[i], "WE ", 3) == 0 && len > 3)
	{
		if (game->map->textur->we)
			return (0);
		game->map->textur->we = ft_strdup(line + 3);
	}
	else if (strncmp(&line[i], "EA ", 3) == 0 && len > 3)
	{
		if (game->map->textur->ea)
			return (0);
		game->map->textur->ea = ft_strdup(line + 3);
	}
	return (1);
}

int	get_texture(t_game *game, char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	len = (int)strlen(&line[i]);
	if (strncmp(&line[i], "C ", 2) == 0 && len > 3)
	{
		if (game->map->textur->ceil)
			return (0);
		game->map->textur->ceil = ft_strdup(&line[i + 2]);
	}
	else if (strncmp(&line[i], "F ", 2) == 0 && len > 3)
	{
		if (game->map->textur->floor)
			return (0);
		game->map->textur->floor = ft_strdup(&line[i + 2]);
	}
	return (get_texture1(game, line, len, i));
}

void	v_texture(t_map *map)
{
	get_path(map->textur->no);
	get_path(map->textur->ea);
	get_path(map->textur->so);
	get_path(map->textur->we);
	rgb_f(map);
	rgb_c(map);
}
