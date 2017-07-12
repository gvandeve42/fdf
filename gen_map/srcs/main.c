#include "gen_map.h"

static void		get_args(char **av, int *args)
{
	args[0] = ft_atoi(av[1]);
	args[1] = ft_atoi(av[2]);
	args[2] = ft_atoi(av[3]);
}

static int		is_good(char **av)
{
	if (ft_is_number(av[1]) &&
		ft_is_number(av[2]) &&
		ft_is_number(av[3]))
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
	if (ac == 4)
		{
			if (is_good(av))
				{
					get_args(av, args);
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
		ft_putstr_fd("usage: gen_map len width higth\n", 2);
	return (1);
}
