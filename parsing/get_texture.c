/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:36:27 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/12 01:49:26 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*delspaces(char *str, char c)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	j = ft_strlen1(str);
	j--;
	while (str[j] && str[j] == c)
		j--;
	j++;
	line = ft_substr1(str, i, j - i);
	return (line);
}

char	*delchar(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			line[i] = '\0';
		i++;
	}
	return (line);
}

int	get_texture2(t_game *game, char *line, int len)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (game->map->textur->west_texture)
			return (0);
		line = delspaces(line, '\n');
		game->map->textur->west_texture = delspaces(line + 3, ' ');
		tmp = line;
	}
	else if (ft_strncmp(line, "EA ", 3) == 0 && len > 3
		&& texture_line(line))
	{
		if (game->map->textur->east_texture)
			return (0);
		line = delspaces(line, '\n');
		game->map->textur->east_texture = delspaces(line + 3, ' ');
		tmp = line;
	}
	free(tmp);
	return (1);
}

int	get_texture1(t_game *game, char *line, int len)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strncmp(line, "NO ", 3) == 0 && len > 3 && texture_line(line))
	{
		if (game->map->textur->no)
			return (0);
		line = delchar(line, '\n');
		game->map->textur->no = delspaces(line + 3, ' ');
		tmp = line;
		return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0 && len > 3
		&& texture_line(line))
	{
		if (game->map->textur->so)
			return (0);
		line = delspaces(line, '\n');
		game->map->textur->so = delspaces(line + 3, ' ');
		free(line);
		return (1);
	}
	return (get_texture2(game, line, len));
}

int	get_texture(t_game *game, char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i] && line[i] == ' ')
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
	return (get_texture1(game, &line[i], len));
}
