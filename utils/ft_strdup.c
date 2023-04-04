/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:21 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/19 14:08:51 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(len * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	while (*s1)
	{
		copy[i] = *s1;
		i++;
		s1++;
	}
	copy[i] = '\0';
	return (copy);
}
