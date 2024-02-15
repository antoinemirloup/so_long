/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:08:11 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 14:30:41 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'F')
	{
		mlx_delete_image(g->mlx, g->sprite.fo);
		mlx_image_to_window(g->mlx, g->sprite.succes, WIDTH / 2 - 375, HEIGHT / 2 - 85);
	}
}

void	set_exit(t_game *g)
{
	g->sprite.nest = mlx_load_png("assets/nest.png");
	if (!g->sprite.nest)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.exit_nest = mlx_texture_to_image(g->mlx, g->sprite.nest);
	mlx_resize_image(g->sprite.exit_nest, g->w_size_x, g->w_size_y / 1.2);
	g->sprite.success = mlx_load_png("assets/success.png");
	if (!g->sprite.success)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.succes = mlx_texture_to_image(g->mlx, g->sprite.success);
	mlx_resize_image(g->sprite.succes, 750, 170);
	mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * WIDTH / \
		g->data.width), (g->data.e_y * HEIGHT / g->data.height));
}
