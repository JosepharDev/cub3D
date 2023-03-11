#include "cub3d.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(len * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	while (*s1)
	{
		copy[i] = *s1;
		i++;
		s1++;
	}
	copy[i] = '\0';
	return (copy);
}