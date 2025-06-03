#include "cub3d.h"

void	handle_map(t_all *all, char *line, int fd)
{
	int	i;

	i = 0;
	all->map->line = malloc(sizeof(char *)
		* (all->height_file - all->pos_line_read_file + 1));
	/* if (!all->map->line)
		error_map("malloc map->line failed!", all);								//a ecrire */
	while(line)
	{
		ft_printf("line = %s\n", line);											//a supprimer
		if (line[0] == '\n')
		{
				free(line);
				line = get_next_line(fd);
				continue;
		}
		else if (ft_strcmp(line, "1") == 0)
		{
			all->map->line[i] = ft_strdup(line);
			/* if (!all->map->line[i])
				error_map("add line map failed!", all);							//a ecrire free toutes les lignes avant */
			i++;
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	all->map->line[i] = NULL;
	ft_printf("on sort de handle_map\n");										//a supprimer
}
