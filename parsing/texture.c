
#include "../cub3d.h"

void	textur_extention(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (str[size - 4] == '.' && str[size - 3] == 'x' 
		&& str[size - 2] == 'p' && str[size - 1] == 'm')
		return ;
	{
		write(2, "ERROR : invalid exetension texture\n", 36);
		exit(1);
	}
}

void	check_existing(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		write(2, "ERROR : THE TEXTURE FILE DOESN'T OPENING\n", 42);
		exit(1);
	}
	close(fd);
}

void	free_textur(char **stock1)
{
	int	i;

	i = 0;
	while (stock1[i])
	{
		free(stock1[i]);
		i++;
	}
	free(stock1);
}

char	*getere(t_game *game, char *what, int go)
{
	char	**stock;
	char	*reture;

	stock = ft_split(game->map_contant[go], ' ', &go);
	if (ft_strncmp(stock[0], what, ft_strlen(stock[0])) == 0 && stock[1])
	{
		if (stock[2])
		{
			write(2, "ERROR IN TEXTURE\n", 18);
			exit(1);
		}
		reture = ft_strdup(stock[1]);
		free_textur(stock);
		return (reture);
	}
	else
	{
		write(2, "ERROR IN TEXTURE\n", 18);
		exit(1);
	}
	return (NULL);
}

void	hndl_textur(t_game *game, int i)
{
	if (game->map_contant[i][0] == 'N')
		game->map->textur->north_texture = getere(game, "NO", i);
	else if (game->map_contant[i][0] == 'S')
		game->map->textur->south_texture = getere(game, "SO", i);
	else if (game->map_contant[i][0] == 'W')
		game->map->textur->west_texture = getere(game, "WE", i);
	else if (game->map_contant[i][0] == 'E')
		game->map->textur->east_texture = getere(game, "EA", i);
}
