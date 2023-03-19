/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:49:45 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/19 09:59:39 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_withspace(t_map *map)
{
	int	k;
	int	nb;
	int	count;
	int	count_width;	

	count = map->height;
	count_width = map->width;
	k = 0;
	while (count > 0)
	{
		if (ft_strlen(map->map[k]) < count_width)
		{
			nb = ft_strlen(map->map[k]);
			while (nb != count_width)
			{
				map->map[k] = ft_strjoin(map->map[k], " ");
				nb++;
			}
			k++;
		}
		else
			k++;
		count--;
	}
}

int	get_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_mlen(char **str)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		len = ft_strlen(str[i]);
		if (j < len)
		{
			j = len;
			i++;
		}
		else
			i++;
	}
	return (j);
}

void	line_del(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == '\n')
			{
				map->map[i][j] = '\0';
			}
			j++;
		}
		i++;
		j = 0;
	}
}
