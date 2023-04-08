/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:43:49 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 11:12:32 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	f2error(void)
{
	write(2, "ERROR : INVALID FILE NAME \n", 28);
	exit(1);
}

void	free_matrix(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
	{
		free(mx[i]);
		i++;
	}
	free(mx);
}

char	*get_last(char *name)
{
	char	**str;
	int		i;
	char	*copy;

	i = 0;
	str = ft_sp(name, '/');
	while (str[i])
		i++;
	copy = ft_strdup(str[i - 1]);
	free_matrix(str);
	return (copy);
}

int	ft_check_extention(char *s)
{
	int	len;
	int	flag;

	flag = 0;
	if (ft_strchr(s, '/') != NULL)
	{
		s = get_last(s);
		flag = 1;
	}
	len = ft_strlen(s);
	if (len > 4 && ft_strncmp(((s + len) - 4), ".cub", 4) == 0)
	{
		if (flag == 1)
			free(s);
		return (1);
	}
	if (flag == 1)
		free(s);
	return (0);
}

void	fcheck_fd(t_game *cub)
{
	char	*line;
	int		fd;

	if (!ft_check_extention(cub->fd))
		f2error();
	fd = open(cub->fd, O_RDONLY);
	if (fd <= 0)
	{
		write(2, "ERROR : --->FD DOESN'T OPENING\n", 32);
		exit(1);
	}
	line = get_next_line_2(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line_2(fd);
	}
	if (!line)
	{
		write(2, "ERROR : --->FD ID EMPTY\n", 25);
		exit(1);
	}
	free(line);
	close(fd);
}
