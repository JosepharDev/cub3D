/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcalc_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:44:22 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/07 11:41:45 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	fcalc_nb(const char *s)
{
	int	nb;
	int	l1;

	nb = 0;
	l1 = 0;
	while (s[l1])
	{
		if (s[l1] < '0' || s[l1] > '9')
		{
			write(2, "error : number of colors\n", 26);
			exit(1);
		}
		l1++;
	}
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + *s - '0';
		if (nb > 255)
		{
			write(2, "error : number of colors\n", 26);
			exit(1);
		}
		s++;
	}
	return (nb);
}
