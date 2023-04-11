/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:19 by yoyahya           #+#    #+#             */
/*   Updated: 2023/04/10 20:35:26 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../cub3d.h"

size_t	ft_strlen0(char *str);
char	*ft_strchr0(char *s, int c);
char	*ft_strjoin0(char *s1, char *s2);

char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *handle);
char	*ft_handle(char *backup);
char	*ft_line(char *handle);

#endif