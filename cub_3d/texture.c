/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 07:42:42 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/04 22:12:09 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

void    file_texture(t_player   *p)
{

    t_img *img= malloc(sizeof(t_img) * 4);

    img[0].img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
            &p->img_e.w, &p->img_e.h);
    img[0].addr = mlx_get_data_addr(img[0].img, &(p->img_e.pixel),
        &(p->img_e.line_length), &(p->img_e.endian));

    //////

    img[1].img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
        &p->img_n.w, &p->img_e.h);
    img[1].addr = mlx_get_data_addr(img[1].img, &(p->img_n.pixel),
        &(p->img_n.line_length), &(p->img_n.endian));
    ///////
    img[2].img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
        &p->img_w.w, &p->img_w.h);
    img[2].addr = mlx_get_data_addr(img[2].img, &(p->img_w.pixel),
        &(p->img_w.line_length), &(p->img_w.endian));
    //////
    img[3].img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
        &p->img_s.w, &p->img_s.h);
    img[3].addr =  mlx_get_data_addr(img[3].img, &(p->img_s.pixel),
        &(p->img_s.line_length), &(p->img_s.endian));

if (!img[0].img || !img[1].img || !img[2].img || !img[3].img)
    {
        write(2, "ERROR : ---> INVALID TEXTURE USE IT", 36);
        exit(1);
    }







    
    // p->img_e.img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
    //         &p->img_e.w, &p->img_e.h);
  
  
    // p->img_n.img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
    //     &p->img_n.w, &p->img_e.h);
 
 
    // p->img_w.img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
    //     &p->img_w.w, &p->img_w.h);
 
 
    // p->img_s.img = mlx_xpm_file_to_image(p->win->mlxp, "ea1.xpm",
    //     &p->img_s.w, &p->img_s.h);


    // if (!p->img_e.img || !p->img_n.img || !p->img_w.img || !p->img_s.img)
    // {
    //     write(2, "ERROR : ---> INVALID TEXTURE USE IT", 36);
    //     exit(1);
    // }
    // p->img_e.addr = mlx_get_data_addr(p->img_e.img, &(p->img_e.pixel),
    //     &(p->img_e.line_length), &(p->img_e.endian));
        
    // printf("address :---%d11111---------",(int)p->img_e.addr);
    // p->img_n.addr = mlx_get_data_addr(p->img_n.img, &(p->img_n.pixel),
    //     &(p->img_n.line_length), &(p->img_n.endian));
        

    // p->img_w.addr = mlx_get_data_addr(p->img_w.img, &(p->img_w.pixel),
    //     &(p->img_w.line_length), &(p->img_w.endian));
    // p->img_s.addr = mlx_get_data_addr(p->img_s.img, &(p->img_s.pixel),
    //     &(p->img_s.line_length), &(p->img_s.endian));
}

// void    flinked_data_addr(t_player  *p)
// {
//     p->img_e.addr = mlx_get_data_addr(pr->img_e.img, &(pr->img_e.pixel),
//         &(pr->img_e.line_length), &(pr->img_e.endian));
//     printf("address : %s11111---------", pr->img_e.addr);
//     pr->img_n.addr = mlx_get_data_addr(pr->img_n.img, &(pr->img_n.pixel),
//         &(pr->img_n.line_length), &(pr->img_n.endian));
//     pr->img_w.addr = mlx_get_data_addr(pr->img_w.img, &(pr->img_w.pixel),
//         &(pr->img_w.line_length), &(pr->img_w.endian));
//     pr->img_s.addr = mlx_get_data_addr(pr->img_s.img, &(pr->img_s.pixel),
//         &(pr->img_s.line_length), &(pr->img_s.endian));
// }

// void    fcheck_valid_texture(t_player   *p)
// {
//     file_texture(p);
//     flinked_data_addr(p);
// }
