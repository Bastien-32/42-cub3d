/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:03:55 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 19:04:19 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *msg)
{
	ft_printf("Error!\n");
	ft_printf("%s\n", msg);
	exit (1);
}

void	error_fd_open(char *msg, int fd, char *line, t_map *map)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (line)
		free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(map);
	exit(1);
}

void	error_fd(char *msg, t_map *map)
{
	free(map);
	error(msg);
}

void	free_args_and_exit(t_map *map, char *msg)
{
	int	i;

	if (!map->line)
		return ;
	i = 0;
	while (i < map->height)
		free(map->line[i++]);
	free(map->line);
	free(map);
	error(msg);
	exit(1);
}
