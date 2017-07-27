#include "gen_map.h"

void	print_map(int **map, int *args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < args[0])
		{
			while (j < args[0])
				{
					ft_printf("%d ", map[i][j]);
					j++;
				}
			ft_printf("\n");
			j = 0;
			i++;
		}
	//ft_printf("\n");
}
