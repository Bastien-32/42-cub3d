/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badal-la <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:14:01 by badal-la          #+#    #+#             */
/*   Updated: 2025/03/03 19:14:26 by badal-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_keymap(t_keymap *keys)
{
	keys->up = KEY_UP;
	keys->down = KEY_DOWN;
	keys->left = KEY_LEFT;
	keys->right = KEY_RIGHT;
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		exit_program(mlx);
	if (mlx->input_locked)
		return (0);
	if (keycode == mlx->keys.up)
		move_player(mlx, 0, -1);
	else if (keycode == mlx->keys.down)
		move_player(mlx, 0, 1);
	else if (keycode == mlx->keys.left)
		move_player(mlx, -1, 0);
	else if (keycode == mlx->keys.right)
		move_player(mlx, 1, 0);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	exit_program(mlx);
	return (0);
}

int	reduce_window(t_mlx *mlx)
{
	draw_map(mlx, mlx->map);
	print_player_and_count_moves(mlx, mlx->player_x, mlx->player_y, 0);
	return (0);
}

void	exit_program(t_mlx *mlx)
{
	free_map(mlx->map);
	free_images(mlx);
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
}
