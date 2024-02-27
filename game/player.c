/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 11:49:12 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player(t_game *g, t_solong *s)
{
	g->sprite.dino_left = mlx_load_png("assets/dino_left.png");
	if (!g->sprite.dino_left)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.dino_right = mlx_load_png("assets/dino_right.png");
	if (!g->sprite.dino_right)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.player_left = mlx_texture_to_image(g->mlx, g->sprite.dino_left);
	g->sprite.player_right = mlx_texture_to_image(g->mlx, g->sprite.dino_right);
	if (mlx_resize_image(g->sprite.player_left, g->size_x, \
		g->size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.player_right, g->size_x, \
		g->size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.player_left, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height)) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.player_left->instances->enabled = true;
	if (mlx_image_to_window(g->mlx, g->sprite.player_right, (s->p_x * WIDTH / \
		(s->width - 1)), (s->p_y * HEIGHT / s->height)) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.player_right->instances->enabled = false;
}
