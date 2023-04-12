/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:36:27 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/12 01:14:13 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(char *line)
{
	int		i;
	int		len;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		ft_error1("Error\ntexture path missing\n", NULL);
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\n')
		j++;
	path = ft_substr1(line, i, j - i);
	len = ft_strlen1(path);
	if (len >= 5 && ft_strncmp(&path[len - 4], ".xpm", 4) == 0)
	{
		free(path);
		return (path);
	}
	else
		ft_error1("Error\npath should include .xmp\n", path);
	free(path);
	return (path);
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

void	v_texture(t_map *map)
{
	get_path(map->textur->no);
	get_path(map->textur->east_texture);
	get_path(map->textur->so);
	get_path(map->textur->west_texture);
	rgb_f(map);
	rgb_c(map);
}
