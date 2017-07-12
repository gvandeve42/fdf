#include "gen_map.h"

static void	init_axe(int *axe, int len)
{
	int	i;

	i = 0;
	while (i < len)
			axe[i++] = INT_MAX;
}

int			**init_map(int *args)
{
	int	**map;
	int	i;

	map = 0;
	i = 0;
	map = (int**)ft_memalloc(args[0] * sizeof(int*));
	while (i < args[0])
		{
			map[i] = (int*)ft_memalloc(args[1] * sizeof(int));
			init_axe(map[i++], args[1]);
		}
	return (map);
}
