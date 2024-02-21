/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/21 15:28:10 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player(t_game *g, t_solong *s)
{
	g->p_size_x = round(WIDTH / (float)(s->width - 1));
	g->p_size_y = round(HEIGHT / (float)(s->height));
	g->sprite.dino = mlx_load_png("assets/dino_idle.png");
	if (!g->sprite.dino)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_left_1 = mlx_load_png("assets/dino_left_1.png");
	if (!g->sprite.dino_left_1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_left_2 = mlx_load_png("assets/dino_left_2.png");
	if (!g->sprite.dino_left_2)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_left_3 = mlx_load_png("assets/dino_left_3.png");
	if (!g->sprite.dino_left_3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_rigth_1 = mlx_load_png("assets/dino_rigth_1.png");
	if (!g->sprite.dino_rigth_1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_rigth_2 = mlx_load_png("assets/dino_rigth_2.png");
	if (!g->sprite.dino_rigth_2)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.dino_rigth_3 = mlx_load_png("assets/dino_rigth_3.png");
	if (!g->sprite.dino_rigth_3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.player = mlx_texture_to_image(g->mlx, g->sprite.dino);
	g->sprite.p_l_1 = mlx_texture_to_image(g->mlx, g->sprite.dino_left_1);
	g->sprite.p_l_2 = mlx_texture_to_image(g->mlx, g->sprite.dino_left_2);
	g->sprite.p_l_3 = mlx_texture_to_image(g->mlx, g->sprite.dino_left_3);
	g->sprite.p_r_1 = mlx_texture_to_image(g->mlx, g->sprite.dino_rigth_1);
	g->sprite.p_r_2 = mlx_texture_to_image(g->mlx, g->sprite.dino_rigth_2);
	g->sprite.p_r_3 = mlx_texture_to_image(g->mlx, g->sprite.dino_rigth_3);
	mlx_resize_image(g->sprite.player, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_l_1, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_l_2, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_l_3, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_r_1, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_r_2, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_resize_image(g->sprite.p_r_3, g->p_size_x * 1.2, g->p_size_y * 0.8);
	mlx_image_to_window(g->mlx, g->sprite.player, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.player->instances->enabled = true;
	mlx_image_to_window(g->mlx, g->sprite.p_l_1, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_l_1->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->sprite.p_l_2, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_l_2->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->sprite.p_l_3, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_l_3->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->sprite.p_r_1, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_r_1->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->sprite.p_r_2, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_r_2->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->sprite.p_r_3, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height));
	g->sprite.p_r_3->instances->enabled = false;
}
