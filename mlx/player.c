/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/13 14:44:16 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player(t_game *g, t_solong *s)
{
	g->p_size_x = WIDTH / (s->width - 1);
	g->p_size_y = HEIGHT / s->height;

	g->sprite.dino = mlx_load_png("assets/dino2.png");
	if (!g->sprite.dino)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.player = mlx_texture_to_image(g->mlx, g->sprite.dino);
	mlx_resize_image(g->sprite.player, g->p_size_x, g->p_size_y);
	mlx_image_to_window(g->mlx, g->sprite.player, (s->p_x * WIDTH / (s->width - 1)), (s->p_y * HEIGHT / s->height));
}
