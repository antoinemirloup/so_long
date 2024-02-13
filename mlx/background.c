/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:00 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/13 14:44:39 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	background(t_game *g)
{
	g->sprite.back = mlx_load_png("assets/zero2.png");
	if (!g->sprite.back)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.background = mlx_texture_to_image(g->mlx, g->sprite.back);
	mlx_resize_image(g->sprite.background, 1.2 * (WIDTH / (float)(g->data.width)), (HEIGHT / (float)(g->data.height)));
	// mlx_image_to_window(g->mlx, g->sprite.background, 0, 0);
	g->data.y = 0;
	while (g->data.y < g->data.height)
	{
		g->data.x = 0;
		while (g->data.x < g->data.width)
		{
			g->w_pos_x = g->data.x * (WIDTH / (float)(g->data.width - 1));
			g->w_pos_y = g->data.y * (HEIGHT / (float)(g->data.height));
			fill_map_pix(g);
			mlx_image_to_window(g->mlx, g->sprite.background, g->w_pos_x, g->w_pos_y);
			g->data.x++;
		}
		g->data.y++;
	}
}
