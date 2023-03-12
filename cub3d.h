#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_data
{
	int fd;
	char *first_map;
	char **map;
	char *resulotion;
	int ind_res;
	char *ceial;
	int ind_ciel;
	char *floor;
	int ind_flor;
	char *NO;
	int ind_NO;
	int NO_fd;
	char *SO;
	int ind_SO;
	int SO_fd;
	char *WE;
	int ind_WE;
	int WE_fd;
	char *EA;
	int ind_EA;
	int EA_fd;
}t_data;


void free_matrix(char **mx);
int is_valid(char *arg, t_data *data);
int check_name(char *name);
char *get_last(char *name);
int ft_error(int flag);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
int get_map(t_data *data);
void map_item(char **map, t_data *data);
void split_map(t_data *data);
#endif