/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:29:36 by sapupier          #+#    #+#             */
/*   Updated: 2025/06/24 11:35:25 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_rgb(const char *str, int *rgb, t_all *all, char *line)
{
	int		i;
	int		j;
	char	**split;
	int		val;

	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		ft_free_split(split, "Error : Invalid RGB format\n", all, line);
	i = -1;
	while (++i < 3)
	{
		j = 0;
		if (!ft_isdigit_and_spaces(split[i]))
			ft_free_split(split, "RGB must be positive numbers\n", all, line);
		while (split[i][j] && (split[i][j] == ' ' || split[i][j] == '\t'))
			j++;
		if (split[i][j] == '\0' || split[i][j] == '\n')
			ft_free_split(split, "RGB value cannot be empty\n", all, line);
		val = ft_atoi(split[i]);
		if (val < 0 || val > 255)
			ft_free_split(split, "RGB value out of limits\n", all, line);
		rgb[i] = val;
	}
	ft_free_split(split, NULL, all, line);
}

void	set_color(t_all *all, char type, const char *str, char *line)
{
	int	rgb[3];

	parse_rgb(str, rgb, all, line);
	if (type == 'F')
	{
		all->text->floor = 1;
		all->text->floor_r = rgb[0];
		all->text->floor_g = rgb[1];
		all->text->floor_b = rgb[2];
	}
	else if (type == 'C')
	{
		all->text->ceiling = 1;
		all->text->ceiling_r = rgb[0];
		all->text->ceiling_g = rgb[1];
		all->text->ceiling_b = rgb[2];
	}
	else
		error_msg_and_close("Error : Unknown color type\n", all);
}

int	is_color(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
		return (1);
	return (0);
}

void	error_colors(int fd, char *line, int error, t_all *all)
{
	char	*msg_err;

	if (error == 0)
		msg_err = "Error: Duplicate floor color\n";
	if (error == 1)
		msg_err = "Error: Duplicate ceiling color\n";
	if (error == 2)
		msg_err = "Error: Duplicate or invalid color\n";
	go_to_end_fd(fd, line);
	error_msg_and_close(msg_err, all);
}

void	handle_colors(t_all *all, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'F')
	{
		if (all->text->floor)
			error_colors(fd, line, 0, all);
		set_color(all, 'F', line + i + 1, line);
		all->text->floor = 1;
	}
	else if (line[i] == 'C')
	{
		if (all->text->ceiling)
			error_colors(fd, line, 1, all);
		set_color(all, 'C', line + i + 1, line);
		all->text->ceiling = 1;
	}
	else
		error_colors(fd, line, 2, all);
}
