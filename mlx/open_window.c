/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/20 16:44:10 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(mlx_key_data_t key, void *param)
{
	t_game	*g;

	g = param;
	g->p_pos_x = g->sprite.player->instances[0].x;
	g->p_pos_y = g->sprite.player->instances[0].y;
	g->p_coord_x = round(g->p_pos_x * g->data.width / WIDTH);
	g->p_coord_y = round(g->p_pos_y * g->data.height / HEIGHT);
	if (key.key == MLX_KEY_W && key.action == 1 && check_up(g) == 1 \
		&& g->success == 0)
		move_up(g);
	if (key.key == MLX_KEY_S && key.action == 1 && check_down(g) == 1 \
		&& g->success == 0)
		move_down(g);
	if (key.key == MLX_KEY_A && key.action == 1 && check_left(g) == 1 \
		&& g->success == 0)
		move_left(g);
	if (key.key == MLX_KEY_D && key.action == 1 && check_rigth(g) == 1 \
		&& g->success == 0)
		move_rigth(g);
	numbers(g);
	collectibles(g);
	exit_game(g);
}

void	ft_hook(void *param)
{
	t_game	*g;

	g = param;
	if (g->success == 0 && g->alive == 1)
		fog(g);
	g->time += g->mlx->delta_time;
	g->c = count_c(&g->data, 'Q') + count_c(&g->data, 'R') + \
		count_c(&g->data, 'S');
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
	g->mlx = mlx_init(WIDTH, HEIGHT, "new window", true);
	mlx_set_window_pos(g->mlx, 1000, 500);
	if (!g->mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	background(g);
	walls(g, s);
	player(g, s);
	g->p_pos_x = g->sprite.player->instances[0].x;
	g->p_pos_y = g->sprite.player->instances[0].y;
	g->p_coord_x = round(g->p_pos_x * g->data.width / WIDTH);
	g->p_coord_y = round(g->p_pos_y * g->data.height / HEIGHT);
	set_collectibles(g);
	set_enemies(g);
	set_fog(g);
	set_exit(g);
	set_numbers(g);
	set_death(g);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	destroy_all(g);
	mlx_terminate(g->mlx);
}
