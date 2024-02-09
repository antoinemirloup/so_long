/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 11:09:35 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_hook(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		g->sprite.player->instances[0].y -= 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		g->sprite.player->instances[0].y += 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		g->sprite.player->instances[0].x -= 20;
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		g->sprite.player->instances[0].x += 20;
}

void	open_window(t_game *g)
{
	g->mlx = mlx_init(WIDTH, HEIGHT, "new window", true);
	mlx_set_window_pos(g->mlx, 1000, 500);
	if (!g->mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	g->sprite.icon = mlx_load_png("assets/icon.png");
	if (!g->sprite.icon)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.back = mlx_load_png("assets/background_test.png");
	if (!g->sprite.back)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.player = mlx_texture_to_image(g->mlx, g->sprite.icon);
	g->sprite.background = mlx_texture_to_image(g->mlx, g->sprite.back);
	mlx_resize_image(g->sprite.background, WIDTH, HEIGHT);
	mlx_resize_image(g->sprite.player, 100, 100);
	mlx_image_to_window(g->mlx, g->sprite.background, 0, 0);
	mlx_image_to_window(g->mlx, g->sprite.player, 0, 0);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	destroy_all(g);
	mlx_terminate(g->mlx);
}
