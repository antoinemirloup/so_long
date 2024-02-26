/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/26 11:00:08 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	looking_direction(mlx_key_data_t key, void *param)
{
	t_game	*g;

	g = param;
	if (key.key == MLX_KEY_A && (key.action == 1 || key.action == 2) \
		&& check_left(g) == 0 && g->success == 0 && g->alive == 1)
	{
		g->sprite.player_left->instances->enabled = true;
		g->sprite.player_right->instances->enabled = false;
	}
	if (key.key == MLX_KEY_D && (key.action == 1 || key.action == 2) \
		&& check_rigth(g) == 0 && g->success == 0 && g->alive == 1)
	{
		g->sprite.player_left->instances->enabled = false;
		g->sprite.player_right->instances->enabled = true;
	}
}

void	move(mlx_key_data_t key, void *param)
{
	t_game	*g;

	g = param;
	g->p_pos_x = g->sprite.player_left->instances[0].x;
	g->p_pos_y = g->sprite.player_left->instances[0].y;
	g->p_coord_x = round(g->p_pos_x * g->data.width / WIDTH);
	g->p_coord_y = round(g->p_pos_y * g->data.height / HEIGHT);
	if (key.key == MLX_KEY_W && (key.action == 1 || key.action == 2) \
		&& check_up(g) == 1 && g->success == 0 && g->alive == 1)
		move_up(g);
	if (key.key == MLX_KEY_S && (key.action == 1 || key.action == 2) \
		&& check_down(g) == 1 && g->success == 0 && g->alive == 1)
		move_down(g);
	if (key.key == MLX_KEY_A && (key.action == 1 || key.action == 2) \
		&& check_left(g) == 1 && g->success == 0 && g->alive == 1)
		move_left(g);
	if (key.key == MLX_KEY_D && (key.action == 1 || key.action == 2) \
		&& check_rigth(g) == 1 && g->success == 0 && g->alive == 1)
		move_rigth(g);
	looking_direction(key, param);
	numbers(g);
	collectibles(g);
	if (g->count > 999)
		exit((ft_printf("you lose!\n"), EXIT_FAILURE));
	exit_game(g);
}

void	ft_hook(void *param)
{
	t_game	*g;

	g = param;
	g->c = count_c(&g->data, 'Q') + count_c(&g->data, 'R') + \
		count_c(&g->data, 'S');
	if (g->success == 0 && g->alive == 1)
		fog(g);
	g->time += g->mlx->delta_time;
	mlx_key_hook(g->mlx, move, (void *)g);
	if (g->time > 0.03)
	{
		g->frame++;
		refresh(g);
		g->time = 0;
	}
	death(g);
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
}

void	open_window(t_game *g, t_solong *s)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!g->mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	mlx_set_window_pos(g->mlx, 1000, 500);
	mlx_set_window_limit(g->mlx, WIDTH, HEIGHT, WIDTH, HEIGHT);
	init_textures(g);
	background(g);
	walls(g, s);
	set_exit(g);
	player(g, s);
	g->p_pos_x = g->sprite.player_left->instances[0].x;
	g->p_pos_y = g->sprite.player_left->instances[0].y;
	g->p_coord_x = round(g->p_pos_x * g->data.width / WIDTH);
	g->p_coord_y = round(g->p_pos_y * g->data.height / HEIGHT);
	set_collectibles(g);
	set_enemies(g);
	set_fog(g);
	set_numbers(g);
	set_death(g);
	set_success(g);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	d_a(g);
	mlx_terminate(g->mlx);
}
