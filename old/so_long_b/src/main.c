/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:06:52 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 19:06:55 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *mlx, t_map *map)
{
	int	screen_width;
	int	screen_height;

	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error("MiniLibX initialization failed!");
	mlx_get_screen_size(mlx->mlx_ptr, &screen_width, &screen_height);
	mlx->tile_size = TILE_SIZE;
	mlx->width_win = (map->width - 1) * mlx->tile_size;
	mlx->height_win = map->height * mlx->tile_size;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
						mlx->width_win, mlx->height_win, "So Long - Badal-la");
	if (!mlx->win_ptr)
		error("Window creation failed!");
	mlx->map = map;
	find_player(mlx, map);
	init_keymap(&mlx->keys);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	mlx;

	if (argc != 2)
		error("Usage : ./so_long [nameofmap.ber]");
	check_file(argv[1]);
	map = parse_map(argv[1]);
	check_map(map);
	init_mlx(&mlx, map);
	load_images(&mlx);
	draw_map(&mlx, map);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, keypress, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, close_window, &mlx);
	mlx_hook(mlx.win_ptr, 12, 1L << 15, reduce_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
