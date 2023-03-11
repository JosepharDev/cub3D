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
int check_element(char *line)
{
	int i;

	i = 0;
	if (strnstr(line, "SO", ) != NULL)
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
	// while(map[i])
	// {
		map[i] = del_space(map[i]);
		if(!check_element(map[i]))
		{
			printf("Error\n");
			exit(1);
		}
		printf("%s\n", map[i]);
	// }
}