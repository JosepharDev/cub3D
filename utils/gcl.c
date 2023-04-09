/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarify <mdarify@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:49:15 by mdarify           #+#    #+#             */
/*   Updated: 2023/04/09 18:02:31 by mdarify          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stock = read_file(fd, stock);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = move_to_rest(stock);
	return (line);
}
