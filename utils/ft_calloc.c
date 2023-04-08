/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:44:31 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 10:44:23 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_bzero(void	*s, size_t	n)
{
	char	*p;

	p = ((char *)s);
	while (n-- > 0)
		p[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
