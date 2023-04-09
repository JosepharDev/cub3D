/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:27:46 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:32:02 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	flinked_xmp_files(t_cub *cub)
{
	cub->img_e.img = mlx_xpm_file_to_image(cub->win->mlx_p,
			cub->map->textur->east_texture, &cub->img_e.w, &cub->img_e.h);
	cub->img_n.img = mlx_xpm_file_to_image(cub->win->mlx_p,
			cub->map->textur->no, &cub->img_n.w, &cub->img_n.h);
	cub->img_w.img = mlx_xpm_file_to_image(cub->win->mlx_p,
			cub->map->textur->west_texture, &cub->img_w.w, &cub->img_w.h);
	cub->img_s.img = mlx_xpm_file_to_image(cub->win->mlx_p,
			cub->map->textur->so, &cub->img_s.w, &cub->img_s.h);
	if (!cub->img_e.img || !cub->img_n.img || !cub->img_w.img
		|| !cub->img_s.img)
	{
		write(2, "ERROR : INVALID XPM FILES\n", 27);
		exit(1);
	}
}

void	flinked_address_images(t_cub *cub)
{
	cub->img_e.addr = mlx_get_data_addr(cub->img_e.img, &(cub->img_e.px),
			&(cub->img_e.l_len), &(cub->img_e.endian));
	cub->img_n.addr = mlx_get_data_addr(cub->img_n.img, &(cub->img_n.px),
			&(cub->img_n.l_len), &(cub->img_n.endian));
	cub->img_w.addr = mlx_get_data_addr(cub->img_w.img, &(cub->img_w.px),
			&(cub->img_w.l_len), &(cub->img_w.endian));
	cub->img_s.addr = mlx_get_data_addr(cub->img_s.img, &(cub->img_s.px),
			&(cub->img_s.l_len), &(cub->img_s.endian));
}

void	fvalid_linked_texture(t_cub *cub)
{
	flinked_xmp_files(cub);
	flinked_address_images(cub);
}
