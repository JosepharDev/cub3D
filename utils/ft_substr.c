/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:38:30 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/19 16:00:25 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned	int	l;
	int				i;
	char			*ptr;

	i = 0;
	ptr = NULL;
	l = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > l)
		return (ft_strdup("\0"));
	if (len > l)
		ptr = malloc(l * sizeof(char) + 1);
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
