/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:54:01 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/11 01:08:54 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_hero(t_map *map, int i, int j)
{
	if (j == 0 && map->map[i][j] != ' ')
	{
		if (map->map[i][j] != '1')
			return (1);
	}
	else if (j == map->width - 1)
	{
		if (map->map[i][j] != ' ')
			if (map->map[i][j] != '1')
				return (1);
	}
	else if (j != 0 && map->map[i][j] != ' ')
	{
		if (map->map[i][j - 1] == ' ' || map->map[i][j + 1] == ' ')
			if (map->map[i][j] != '1')
				return (1);
	}
	return (0);
}

int	check_heroz(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (check_hero(map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_ver(t_map *map, int i, int j)
{
	if (i == 0 && map->map[i][j] != ' ')
	{
		if (map->map[i][j] != '1')
			return (1);
	}
	else if (i == map->height - 1)
	{
		if (map->map[i][j] != ' ')
			if (map->map[i][j] != '1')
				return (1);
	}
	else if (i != 0 && map->map[i][j] != ' ')
	{
		if (map->map[i - 1][j] == ' ' || map->map[i + 1][j] == ' ')
			if (map->map[i][j] != '1')
				return (1);
	}
	return (0);
}

int	check_verti(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->width)
	{
		i = 0;
		while (i < map->height)
		{
			if (check_ver(map, i, j) == 1)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	valid_map(t_map *map)
{
	map->width -= 1;
	line_del(map);
	map_withspace(map);
	if (check_verti(map) || check_heroz(map))
		ft_error1("Error\ninvalid map\n", NULL);
	get_player(map);
}
