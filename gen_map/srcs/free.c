#include "gen_map.h"

void	free_map(int **map, int *args)
{
	int	i;

	i = 0;
	while (i < args[0])
		free(map[i++]);
	free(map);
}
