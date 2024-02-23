/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:32:40 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 14:23:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fog_to_window(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.fogg1, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2))) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fogg1->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.fogg2, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2))) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fogg2->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.fogg3, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2))) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fogg3->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.fogg4, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2))) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fogg4->instances->enabled = false;
}

void	set_fog(t_game *g)
{
	g->sprite.fog1 = mlx_load_png("assets/fog1.png");
	if (!g->sprite.fog1)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fog2 = mlx_load_png("assets/fog2.png");
	if (!g->sprite.fog2)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fog3 = mlx_load_png("assets/fog3.png");
	if (!g->sprite.fog3)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fog4 = mlx_load_png("assets/fog4.png");
	if (!g->sprite.fog4)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.fogg1 = mlx_texture_to_image(g->mlx, g->sprite.fog1);
	g->sprite.fogg2 = mlx_texture_to_image(g->mlx, g->sprite.fog2);
	g->sprite.fogg3 = mlx_texture_to_image(g->mlx, g->sprite.fog3);
	g->sprite.fogg4 = mlx_texture_to_image(g->mlx, g->sprite.fog4);
	fog_to_window(g);
}
