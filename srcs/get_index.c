
#include "lem_in.h"

int	get_index(t_map *map, char *name)
{
	int	i;

	i = 0;
	while (i < map->rooms_count && ft_strcmp(map->rooms[i], name))
		i++;
	if (i == map->rooms_count)
		ft_error_exit("ERROR\n");
	return (i);
}
