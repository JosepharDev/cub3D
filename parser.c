#include "cub3d.h"

char *get_last(char *name)
{
	char **str;
	int i;
	char *copy;

	i = 0;
	str = ft_split(name, '/');
	while(str[i])
		i++;
	copy = ft_strdup(str[i - 1]);
	free_matrix(str);
	return (copy);
}

int check_name(char *name)
{
	int len;
	char *copy;
	int flag = 0;
	if (strchr(name, '/') != NULL)
	{
		name = get_last(name);
		flag = 1;
	}
	len = strlen(name);
	if (len > 4 && strncmp(((name + len) - 4), ".cub", 4) == 0)
	{
		if (flag == 1)
			free(name);
		return (1);
	}
	if (flag == 1)
		free(name);
	return (0);
}

int is_valid(char *arg, t_data *data)
{
	if (!check_name(arg))
	{
		printf("invalid file name\n");
		exit(1);
	}
	else
	{
		data->fd = open(arg, O_RDONLY);
		if (data->fd == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	return (1);
}

int get_map(t_data *data)
{
	int i;
	char *line;
	char *map;

	map = NULL;
	i = 0;
	line = get_next_line(data->fd);
	while(line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(data->fd);
	}
	data->first_map = map;
	return (1);
}
void split_map(t_data *data)
{
	int i;
	char **tmp;
	i = 0;
	tmp = ft_split(data->first_map, '\n');
	map_item(tmp, data);
}