/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/08 16:14:14 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static mlx_image_t	*player;
static mlx_image_t	*background;

void	ft_hook(void *param)
{
	mlx_t		*mlx;
	// t_sprite	*s;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		player->instances[0].y -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		player->instances[0].y += 20;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		player->instances[0].x -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		player->instances[0].x += 20;
}

void	open_window(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*icon;
	mlx_texture_t	*back;
	// t_sprite		*s;

	mlx = mlx_init(WIDTH, HEIGHT, "new window", true);
	if (!mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	icon = mlx_load_png("assets/icon.png");
	if (!icon)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	back = mlx_load_png("assets/background_test.png");
	if (!back)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	player = mlx_texture_to_image(mlx, icon);
	background = mlx_texture_to_image(mlx, back);
	mlx_resize_image(background, WIDTH, HEIGHT);
	mlx_resize_image(player, 100, 100);
	mlx_image_to_window(mlx, background, 0, 0);
	mlx_image_to_window(mlx, player, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
