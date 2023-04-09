/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:48:04 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:33:42 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const	char	*s)
{
	char	*pdf;
	int		size;
	int		len;

	size = 0;
	len = 0;
	while (s[size])
		size++;
	size++;
	pdf = (char *)malloc (sizeof(char) * size);
	while (len < size)
	{
		pdf[len] = s[len];
		len++;
	}
	pdf[len] = '\0';
	return (pdf);
}
