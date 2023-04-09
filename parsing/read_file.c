/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:35:45 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/09 12:23:28 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	all_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n' && line[i + 1] == '\0')
		return (1);
	else
		return (0);
}

int	white_s(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t' || line[i] == '\r'
			|| line[i] == '\f' || line[i] == '\v')
			return (0);
		i++;
	}
	return (1);
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 01WNSE\n", line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	read_file1(t_game *game, int fd)
{
	int		i;
	char	*line;
	char	*map;

	map = NULL;
	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error1("Error\nfile is empty\n", NULL);
	while (line)
	{
		if (line[0] == '\n')
		{
			if (game->map->map)
				ft_error1("Error\ninvalid map newline within the map\n", NULL);
		}
		else if (line[0] != '\n')
			check_line(game, line);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
