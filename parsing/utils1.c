/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:36:25 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/08 17:29:40 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	len_matrix(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !arr[0])
		return (0);
	while (arr[i])
		i++;
	return (i);
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

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**dup_matrix(char **arr, char *line)
{
	int		len;
	char	**d;
	int		i;

	i = 0;
	len = len_matrix(arr);
	d = malloc(sizeof(char *) * (len + 2));
	if (!d)
		exit(22);
	while (i < len)
	{
		d[i] = ft_strdup(arr[i]);
		if (!d[i])
			exit(44);
		i++;
	}
	d[i] = ft_strdup(line);
	d[i + 1] = NULL;
	free_matrix(arr);
	return (d);
}
