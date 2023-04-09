/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:48:47 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 12:06:07 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strcat(char *pdf, char *dest, char *src)
{
	int	m;
	int	n;
	int	j;

	m = 0;
	n = 0;
	j = 0;
	while (dest[m] != '\0')
	{
		pdf[j] = dest[m];
		m++;
		j++;
	}
	while (src[n] != '\0')
	{
		pdf[j + n] = src[n];
		n++;
	}
	pdf[j + n] = '\0';
	return (pdf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_index;
	size_t	z_index;
	char	*pdf;
	char	*src;
	char	*dst;

	src = (char *)s1;
	dst = (char *)s2;
	if (!s1 || !s2)
		return (0);
	s_index = ft_strlen(s1);
	z_index = ft_strlen(s2) + 1;
	pdf = (char *)malloc((s_index + z_index) * sizeof(char));
	if (!pdf)
		return (NULL);
	pdf = ft_strcat(pdf, src, dst);
	return (pdf);
}
