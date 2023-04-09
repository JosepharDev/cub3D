/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:47:44 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/09 15:22:31 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color1(char **rgb)
{
	int	n1;
	int	n2;
	int	n3;
	int	res;

	res = 0;
	n1 = ft_atoi(rgb[0]);
	n2 = ft_atoi(rgb[1]);
	n3 = ft_atoi(rgb[2]);
	if (n1 < 0 || n1 > 255 || n2 < 0 || n2 > 255 || n3 < 0 || n3 > 255)
		ft_error1("Error\nRGB out of range\n", NULL);
	res += n1 * 256 * 256;
	res += n2 * 256;
	res += n3;
	return (res);
}

void	replace_char(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == c)
		{
			line[i] = ' ';
			i++;
		}
		else
			i++;
	}
}

int	check_semi(char *line)
{
	int	i;
	int	sem;

	i = 0;
	sem = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '-' || ft_isalpha1(line[i]))
			return (-1);
		else if (line[i] == ',')
			sem++;
		else if (line[i] == ' ')
		{
			i++;
			continue ;
		}
		else if (!ft_isdigit1(line[i]))
			return (-1);
		i++;
	}
	return (sem);
}

void	rgb_f(t_map *map)
{
	int		i;
	char	**rgb;

	i = check_semi(map->textur->floor);
	if (i == -1 || i != 2)
		ft_error1("Error\ninvalid texture\n", NULL);
	replace_char(map->textur->floor, ',');
	rgb = ft_split1(map->textur->floor, ' ');
	if (len_matrix(rgb) != 3)
	{
		if (len_matrix(rgb) == 3 && rgb[2][0] != '\n')
		{
			free_matrix(rgb);
			ft_error1("Error\ninvalid rgb\n", NULL);
		}
	}
	map->f_c = get_color1(rgb);
	free_matrix(rgb);
	return ;
}

void	rgb_c(t_map *map)
{
	int		i;
	char	**rgb;

	i = check_semi(map->textur->ceil);
	if (i == -1 || i != 2)
		ft_error1("Error\ninvalid texture\n", NULL);
	replace_char(map->textur->ceil, ',');
	rgb = ft_split1(map->textur->ceil, ' ');
	if (len_matrix(rgb) != 3)
	{
		if (len_matrix(rgb) == 3 && rgb[2][0] != '\n')
		{
			free_matrix(rgb);
			ft_error1("Error\ninvalid rgb\n", NULL);
		}
	}
	map->c_c = get_color1(rgb);
	free_matrix(rgb);
	return ;
}
