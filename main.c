#include "cub3d.h"

int ft_error(int flag)
{
	if (flag == 0)
		printf("Invalid argumment\n");
	else if (flag == 1)
		printf("map Not valid\n");
	return (1);
}

int main(int ac, char **av)
{
	t_data data;
	if (ac != 2)
		return (ft_error(0));
	if (!is_valid(av[1], &data))
		return (ft_error(1));
	if (!get_map(&data))
		return (ft_error(1));
	split_map(&data);
	// printf("%s", data.first_map);
	printf("%s", data.map[0]);
	// while(1);
	return (99);
}