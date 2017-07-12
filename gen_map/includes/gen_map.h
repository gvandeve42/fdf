#ifndef GEN_MAP_H
# define GEN_MAP_H

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int		**init_map(int *args);
void	free_map(int **map, int *args);
void	print_map(int **map, int *args);
void	modify_map(int **map, int *args);

#endif
