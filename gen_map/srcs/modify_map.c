#include "gen_map.h"

static int		rand_sign(int nb)
{
	int		sign;

	sign = rand() % 2;
	if (sign > 0)
		return (rand() % nb);
	else
		return (-(rand() % nb));
}

static void		add_rdm(int *coor, int *rdm_nbr)
{
	*coor += rand_sign(*rdm_nbr);
	if (*rdm_nbr > 2)
		*rdm_nbr -= 1;
}

static void		calc(int **map, int i, int j, int len, int *args)
{
	int res;
	int	div;

	res = 0;
	div = 0;
	if (i - len / 2 >= 0)
	{
		res += map[i - len / 2][j];
		div++;
	}
	if (i + len / 2 < args[0] - 1)
	{
		res += map[i + len / 2][j];
		div++;
	}
	if (j - len / 2 >= 0)
	{
		res += map[i][j - len / 2];
		div++;
	}
	if (j + len / 2 < args[0] - 1)
	{
		res += map[i][j + len / 2];
		div++;
	}
	res /= div;
	map[i][j] = res;
	add_rdm(&(map[i][j]), &args[2]);
}

static void		do_square(int **map, int *coor, int len, int *args)
{
	calc(map, coor[0] - len / 2, coor[1], len, args);
	calc(map, coor[0], coor[1] + len / 2, len, args);
	calc(map, coor[0], coor[1] - len / 2, len, args);
	calc(map, coor[0] + len / 2, coor[1], len, args);
}

static void		square_step(int **map, int *args, int len ,int count)
{
	int	i;
	int	j;
	int coor[2];
	int n;

	i = 0;
	j = 0;
	n = count;
	while (n > 0)
	{
		while (((len / 2) + (j * len)) < args[0])
		{
			coor[0] = ((len / 2) + (i * len));
			coor[1] = ((len / 2) + (j * len));
			do_square(map, coor, len, args);
			j++;
			n--;
		}
		j = 0;
		i++;
	}
}

static void		diamond_step(int **map, int *args, int len ,int count)
{
	int	i;
	int	j;
	int	coor[2];

	i = 0;
	j = 0;
	while (count > 0)
	{
		while (((len / 2) + (j * len)) < args[0])
		{
			coor[0] = ((len / 2) + (i * len));
			coor[1] = ((len / 2) + (j * len));
			map[coor[0]][coor[1]] =
				(map[coor[0] - (len / 2)][coor[1] - (len / 2)] +
				 map[coor[0] - (len / 2)][coor[1] + (len / 2)] +
				 map[coor[0] + (len / 2)][coor[1] - (len / 2)] +
				 map[coor[0] + (len / 2)][coor[1] + (len / 2)]) / 4;
			//ft_printf("DMD BF RDM\n");
			//print_map(map, args);
			//ft_printf("DMD AFT RDM\n");
			//print_map(map, args);
			add_rdm(&(map[coor[0]][coor[1]]), &args[2]);
			j++;
			count--;
		}
		j = 0;
		i++;
	}
}

void			diam_sqr(int **map, int* args)
{
	int	len;
	int	count;

	len = args[0];
	while (len > 1)
	{
		count = (args[0] / len) * (args[0] / len);
		diamond_step(map, args, len, count);
		square_step(map, args, len, count);
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
