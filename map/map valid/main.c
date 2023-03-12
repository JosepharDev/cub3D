#include "../cub3d.h"

void parse_map(char *map)
{
	char **ful_map;
	ful_map = ft_split(map, '\n');
	if (check_map(ful_map) == 1)
	{
		exit(12);
	}
}

int main(int ac, char **av)
{
	char *line;
	char *map = NULL;
	int fd = open("d copy", O_RDONLY);
	if (fd == -1)
		exit(100);
	line = get_next_line(fd);
	while(line)
	{
		map = ft_strjoin(map, line);
		line = get_next_line(fd);
	}
	parse_map(map);
}