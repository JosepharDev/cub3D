/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:44:59 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/10 22:13:07 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_v(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && ft_isdigit1(str[i]))
			ft_error1("Error\nSpace Within RGB Color\n", NULL);
	}
}

int	ft_atoi(char *str)
{
	int					i;
	unsigned long long	nbr;
	int					sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		nbr = (nbr * 10) + str[i++] - 48;
	check_v(&str[i]);
	return ((int)(nbr * sign));
}
