/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:00 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 11:13:59 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	background(t_game *g)
{
	g->sprite.back = mlx_load_png("assets/background_test2.png");
	if (!g->sprite.back)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.background = mlx_texture_to_image(g->mlx, g->sprite.back);
	mlx_resize_image(g->sprite.background, WIDTH, HEIGHT);
	mlx_image_to_window(g->mlx, g->sprite.background, 0, 0);
}
