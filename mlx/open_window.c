/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 17:11:45 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_hook(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W) && g->data.map[(g->sprite.player->instances[0].y * g->data.height / HEIGHT)][(g->sprite.player->instances[0].x * (g->data.width) / WIDTH)] != '1')
		g->sprite.player->instances[0].y -= 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_S) && g->data.map[(g->sprite.player->instances[0].y * g->data.height / HEIGHT) + 1][(g->sprite.player->instances[0].x * (g->data.width) / WIDTH)] != '1')
		g->sprite.player->instances[0].y += 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_A) && g->data.map[(g->sprite.player->instances[0].y * g->data.height / HEIGHT)][((g->sprite.player->instances[0].x * (g->data.width) / WIDTH) - 1)] != '1')
		g->sprite.player->instances[0].x -= 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_D) && g->data.map[(g->sprite.player->instances[0].y * g->data.height / HEIGHT)][((g->sprite.player->instances[0].x * (g->data.width) / WIDTH) + 1)] != '1')
		g->sprite.player->instances[0].x += 20;
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
	exit_game(g, s);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	destroy_all(g);
	mlx_terminate(g->mlx);
}
