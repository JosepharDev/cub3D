/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:36:55 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/08 10:44:58 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		p;
	char	v;

	p = 0;
	i = 0;
	v = (char )c;
	if (s[i] == '\0' && v == '\0')
	{
		return ((char *)&s[i]);
	}
	while (s[i])
	{
		if (s[i] == v)
			p = i;
		i++;
	}
	if (v == '\0')
		return ((char *)&s[i]);
	if (p == 0 && s[0] != v)
		return (0);
	return ((char *)&s[p]);
}
