/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:30 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/08 17:32:31 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr1(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen1(s))
		return (ft_strdup1("\0"));
	if (len > (size_t)ft_strlen1(s))
		ptr = malloc(ft_strlen(s) * sizeof(char) + 1);
	else
		ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[start] && len)
	{
		ptr[i++] = s[start];
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
