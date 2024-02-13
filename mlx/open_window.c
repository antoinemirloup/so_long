/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:13 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(mlx_key_data_t key, void *param)
{
	t_game	*g;

	g = param;
	g->p_pos_x = g->sprite.player->instances[0].x;
	g->p_pos_y = g->sprite.player->instances[0].y;
	if (key.key == MLX_KEY_W && key.action == 1 && check_up(g) == 1)
		g->sprite.player->instances[0].y -= g->p_size_y;
	if (key.key == MLX_KEY_S && key.action == 1 && check_down(g) == 1)
		g->sprite.player->instances[0].y += g->p_size_y;
	if (key.key == MLX_KEY_A && key.action == 1 && check_left(g) == 1)
		g->sprite.player->instances[0].x -= g->p_size_x;
	if (key.key == MLX_KEY_D && key.action == 1 && check_rigth(g) == 1)
		g->sprite.player->instances[0].x += g->p_size_x;
}

void	ft_hook(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	mlx_key_hook(g->mlx, move, (void *)g);
	collectibles(g);
}

void	open_window(t_game *g, t_solong *s)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "new window", true);
	mlx_set_window_pos(g->mlx, 1000, 500);
	if (!g->mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	// background(g);
	walls(g, s);
	// collectibles(g, s);
	player(g, s);
	// exit_game(g, s);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	destroy_all(g);
	mlx_terminate(g->mlx);
}
