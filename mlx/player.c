/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 17:14:56 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player(t_game *g, t_solong *s)
{
	g->sprite.dino = mlx_load_png("assets/dino2.png");
	if (!g->sprite.dino)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.player = mlx_texture_to_image(g->mlx, g->sprite.dino);
	mlx_resize_image(g->sprite.player, 130, 100);
	mlx_image_to_window(g->mlx, g->sprite.player, (s->p_x * WIDTH / s->width), (s->p_y * HEIGHT / s->height));
}
