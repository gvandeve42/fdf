#include "gen_map.h"

static void		apply_change(int **map, int i, int j, int *args)
{
	int	value;

	value = rand() % args[2];
	value = ((rand() % 2) == 0) ? -value : value;
	if (i > 0 && map[i - 1][j] == INT_MAX)
		map[i - 1][j] = map[i][j] + value;
	if (i < args[0] - 1 && map[i + 1][j] == INT_MAX)
		map[i + 1][j] = map[i][j] + value;
	if (j > 0 && map[i][j - 1] == INT_MAX)
		map[i][j - 1] = map[i][j] + value;
	if (j < args[1] - 1 && map[i][j + 1] == INT_MAX)
		map[i][j + 1] = map[i][j] + value;
}

static void		layer(int **map, int *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < args[0])
		{
			while (j < args[1])
				{
					if (map[i][j] != INT_MAX)
						apply_change(map, i, j, args);
					j++;
				}
			i++;
			j = 0;
		}
}

static int		is_limits(int **map, int *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < args[0])
		{
			while (j < args[1])
				{
					if (map[i][j] == INT_MAX)
						return (1);
					j++;
				}
			i++;
			j = 0;
		}
	return (0);
}

void			modify_map(int **map, int *args)
{
	int	i;
	int	j;

	i = args[0] / 2;
	j = args[1] / 2;
	map[i][j] = (rand() % args[2]);
	while (is_limits(map, args))
		layer(map, args);
}
