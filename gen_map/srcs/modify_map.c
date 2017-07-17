#include "gen_map.h"

void			diam_sqr(int **map, int* args)
{
	int	len;
	int	count;

	len = args[0];
	while (len > 1)
	{
		count = (args[0] / len) * (args[0] / len);
		ft_printf("TEST: len=%d, count=%d\n", len, count);
		//diamond_step(map, args, len, count);
		//square_step(map, args, len, count);
		len /= 2;
	}
}

void			modify_map(int **map, int *args)
{
	map[0][0] = (rand() % args[1]);
	map[args[0] - 1][args[0] - 1] = (rand() % args[1]);
	map[args[0] - 1][0] = (rand() % args[1]);
	map[0][args[0] - 1] = (rand() % args[1]);
	diam_sqr(map, args);
}










