/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:30 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/18 12:44:42 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup("\0"));
	}
	if (len > ft_strlen(s))
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
