/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:34:45 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/27 11:07:33 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*get_last(char *name)
{
	char	**str;
	int		i;
	char	*copy;

	i = 0;
	str = ft_split(name, '/');
	while (str[i])
		i++;
	copy = ft_strdup(str[i - 1]);
	free_matrix(str);
	return (copy);
}

// add ft_strncmp function
int	check_name(char *name)
{
	int		len;
	int		flag;

	flag = 0;
	if (strchr(name, '/') != NULL)
	{
			name = get_last(name);
			flag = 1;
	}
	len = strlen(name);
	if (len > 4 && strncmp(((name + len) - 4), ".cub", 4) == 0)
	{
		if (flag == 1)
			free(name);
		return (1);
	}
	if (flag == 1)
		free(name);
	return (0);
}

int	is_valid(char *arg)
{
	int	fd;

	fd = 0;
	if (!check_name(arg))
		ft_error("Error\ninvalid file name\n", NULL);
	else
	{
		fd = open(arg, O_RDONLY);
		if (fd == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	return (fd);
}
