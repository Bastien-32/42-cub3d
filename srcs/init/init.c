#include "cub3d.h"

int	check_map_name(char *str)
{
	int	len_name_file;

	len_name_file = ft_strlen(str);
	if (ft_strcmp(".cub",str + len_name_file - 4) == 0)
		return(1);
	ft_putstr_fd("error : name map is not in .cub\n", 2);
	return (0);
}

t_all	*init_all(int argc, char **argv)
{
	t_all	*all;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("error : usage : ./philo [map_name].cub\n", 2);
		return (NULL);
	}
	if(!check_map_name(argv[1]))
		return (NULL);
	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->height_file = 0;
	all->pos_line_read_file = 0;

	//init_map(all, argv[1]);
	//ft_printf("ok\n");
	return (all);
}
