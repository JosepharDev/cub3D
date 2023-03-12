#include "cub3d.h"

void free_matrix(char **mx)
{
	int i = 0;
	while(mx[i])
	{
		free(mx[i]);
		i++;
	}
	free(mx);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}
int check_element2(char *line, t_data *data, int index)
{
	if (strnstr(line, "F ", ft_strlen(line)) != NULL)
	{
		data->floor = line;
		data->ind_flor = index;
		return (1);
	}
	else if (strnstr(line, "C ", ft_strlen(line)) != NULL)
	{
		data->ceial = line;
		data->ind_ciel = index;
		return (1);
	}
	// else if ()
	printf("==%s\n", line);
	return (0);
}

int check_element(char *line, t_data *data, int index)
{
	if (strnstr(line, "SO ", ft_strlen(line)) != NULL)
	{
		data->SO = line;
		data->ind_SO = index;
		return (1);
	}
	else if (strnstr(line, "EA ", ft_strlen(line)) != NULL)
	{
		data->EA = line;
		data->ind_EA = index;
		return (1);
	}
	else if (strnstr(line, "WE ", ft_strlen(line)) != NULL)
	{
		data->WE = line;
		data->ind_WE = index;
		return (1);
	}
	else if (strnstr(line, "NO ", ft_strlen(line)) != NULL)
	{
		data->NO = line;
		data->ind_NO = index;
		return (1);
	}
	return (check_element2(line, data, index));
}

char *del_space(char *line)
{
	int i;
	int count;
	char *tmp;
	int j;

	j = 0;
	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	tmp = malloc(sizeof(char) * (i - count) + 2);
	count = 0;
	i = 0;
	while(line[i])
	{
		if(line[i] == ' ')
		{
			tmp[j] = line[i];
			i++;
			j++;
			while(line[i] && line[i] == ' ')
				i++;
		}
		else
		{
			while(line[i] && line[i] != ' ')
			{
				tmp[j] = line[i];
				i++;
				j++;
			}
		}
	}
	tmp[j] = '\0';
	free(line);
	return (tmp);
}

void map_item(char **map, t_data *data)
{
	int i = 0;
	while(map[i])
	{
		map[i] = del_space(map[i]);
		if(!check_element(map[i], data, i))
		{
			printf("Error\n");
			exit(1);
		}
		printf("%s\n", map[i]);
		i++;
	}
}