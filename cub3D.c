/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:33 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 22:53:05 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}
int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error1("Error\nnumber of arg not valid\n", NULL);
	parser(&game, av[1]);
	rendering_cub3d(game.map);
	free_matrix(game.map->map);
	while(1);
	return (99);
}