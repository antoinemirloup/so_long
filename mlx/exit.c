/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:08:11 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 17:10:46 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_game *g, t_solong *s)
{
	g->sprite.nest = mlx_load_png("assets/nest.png");
	if (!g->sprite.nest)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.exit_nest = mlx_texture_to_image(g->mlx, g->sprite.nest);
	mlx_resize_image(g->sprite.exit_nest, 130, 100);
	mlx_image_to_window(g->mlx, g->sprite.exit_nest, (s->e_x * WIDTH / s->width), (s->e_y * HEIGHT / s->height));
}