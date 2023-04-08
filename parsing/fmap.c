/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:42:48 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/07 10:42:56 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error("Map must be closed/surrounded by walls.\n");
		i++;
	}
}

void	check_characters(char c)
{
	if (c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != '0')
		ft_error("Map must be contian (10SNEW).\n");
}

void	check_is_closed(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i] && i < size)
	{
		j = -1;
		while (map[i][++j] && j < ft_strlen(map[i]))
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				check_characters(map[i][j]);
				if (map[i - 1][j] && map[i][j - 1]
					&& map[i][j + 1] && map[i + 1][j])
				{
					if (map[i - 1][j] == ' ' || map[i][j - 1] == ' '
						|| map[i][j + 1] == ' ' || map[i + 1][j] == ' ')
						ft_error("error in map\n");
				}
				else
					ft_error("Map must be closed/surrounded by walls.\n");
			}
		}
	}
}

void	check_map(t_map *map)
{	
	check_line(map->map[0]);
	check_is_closed(map->map, map->height);
	check_line(map->map[map->height - 1]);
}
