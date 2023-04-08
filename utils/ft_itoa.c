/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:44:38 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/07 11:46:15 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_size_count(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static	char	*ft_prt(char *accumulator, int nb, int size)
{
	if (!accumulator)
		return (NULL);
	accumulator[size - 1] = '\0';
	size = size - 2;
	if (nb < 0)
	{
		accumulator[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		accumulator[size--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (accumulator);
}

char	*ft_itoa(int n)
{
	char	*current;
	int		size;
	int		m;

	m = n;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size_count(n);
	size++;
	current = (char *)malloc(sizeof(char) * (size));
	if (!current)
		return (NULL);
	current = ft_prt(current, m, size);
	return (current);
}
