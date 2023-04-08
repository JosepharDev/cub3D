/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:33 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 10:02:51 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	*cub;

	if (argc != 2)
	{
		write(2, "ERROR : --> INVALID EXECUTABLE\n", 32);
		exit(1);
	}
	cub = malloc(sizeof(t_game));
	cub->fd = ft_strdup(argv[1]);
	fcheck_fd(cub);
	fsetting(cub);
	rendering_cub3d(cub->map);
	return (0);
}
