/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:00 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 10:06:22 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	background(t_game *g)
{
	g->sprite.back = mlx_load_png("assets/background_test2.png");
	if (!g->sprite.back)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.background = mlx_texture_to_image(g->mlx, g->sprite.back);
	if (mlx_resize_image(g->sprite.background, WIDTH, HEIGHT) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.background, 0, 0) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}
