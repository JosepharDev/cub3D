/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:21 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/11 23:44:20 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup1(char *s1)
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
