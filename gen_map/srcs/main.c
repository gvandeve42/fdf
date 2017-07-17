#include "gen_map.h"

static int		power(int nbr, int iter)
{
	int	tmp;

	tmp = nbr;
	while (iter > 0)
	{
		nbr *= tmp;
		iter--;
	}
	return (nbr);
}

static int		is_valid_number(int nbr)
{
	int	i;

	i = 1;
	while (i < 8)
	{
		if (nbr == (power(2, i) + 1))
			return (1);
		i++;
	}
	return (0);
}

static int		get_args(char **av, int *args)
{
	args[0] = ft_atoi(av[1]);
	args[1] = ft_atoi(av[2]);
	if (!is_valid_number(args[0]))
	{
		ft_putstr_fd("error: first argument must be (2^n + 1), with 0<n<8\n", 2);
		return (0);
	}
	if (args[1] < 2)
	{
		ft_putstr_fd("error: the random number must be at least 2\n", 2);
		return (0);
	}
	return (1);
}

static int		is_good(char **av)
{
	if (ft_is_number(av[1]) &&
		ft_is_number(av[2]))
		return (1);
	else
		return (0);
}

int				main(int ac, char **av)
{
	int		**map;
	int		args[3];

	map = 0;
	srand(time(NULL));
	if (ac == 3)
		{
			if (is_good(av))
				{
					if (!get_args(av, args))
						return (1);
					map = init_map(args);
					modify_map(map, args);
					print_map(map, args);
					free_map(map, args);
					return (0);
				}
			else
				ft_putstr_fd("error: Bad args...\n", 2);
		}
	else
		ft_putstr_fd("usage: gen_map len rdm_variety\n", 2);
	return (1);
}






