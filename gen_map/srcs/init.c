#include "gen_map.h"

int			**init_map(int *args)
{
	int	**map;
	int	i;

	map = 0;
	i = 0;
	map = (int**)ft_memalloc(args[0] * sizeof(int*));
	while (i < args[0])
		{
			map[i] = (int*)ft_memalloc(args[0] * sizeof(int));
			i++;
		}
	return (map);
}
