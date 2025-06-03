#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

#include <unistd.h>


typedef struct s_map
{
	char	**line; //tableau de lignes
}			t_map;

/* typedef struct s_text
{
	int		i; //bidon juste pour creer la structure
}			t_text; */

typedef struct s_all
{
	int			height_file;
	int			pos_line_read_file;
	t_map		*map;
	//t_text		*text;
}			t_all;

/* ====	init.c	=============================================================*/

int		check_map_name(char *str);
t_all	*init_all(int argc, char **argv);

/* ====	parsing.c	=========================================================*/

void	parse_map(t_all *all, char *file);

/* ====	handle_map.c	=========================================================*/

void	handle_map(t_all *all, char *line, int fd);

/* ====	x	=========================================================*/



#endif