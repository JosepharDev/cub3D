/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:42:23 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/20 07:53:54 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("Error\nnumber of arg not valid\n", NULL);
	parser(&game, av[1]);
	int i;
	i = 0;
	while(game.map->map[i])
	{
		printf("%s\n", game.map->map[i]);
		i++;
	}
	printf("--%c\n", game.map->start_p);
	printf("--%d\n", game.map->player.px);
	printf("--%d\n", game.map->player.py);
	
	return (99);
}
