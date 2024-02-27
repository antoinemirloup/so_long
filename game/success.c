/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:11:53 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 11:56:40 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_success(t_game *g)
{
	g->sprite.player_left->instances->enabled = false;
	g->sprite.player_right->instances->enabled = false;
	if (g->win == 0)
	{
		g->sprite.win1->instances->enabled = true;
		g->sprite.win2->instances->enabled = false;
		g->win = 1;
	}
	else if (g->win == 1)
	{
		g->sprite.win2->instances->enabled = true;
		g->sprite.win1->instances->enabled = false;
		g->win = 0;
	}
}

void	set_success(t_game *g)
{
	g->sprite.win_1 = mlx_load_png("assets/win_1.png");
	if (!g->sprite.win_1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.win_2 = mlx_load_png("assets/win_2.png");
	if (!g->sprite.win_2)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.win1 = mlx_texture_to_image(g->mlx, g->sprite.win_1);
	g->sprite.win2 = mlx_texture_to_image(g->mlx, g->sprite.win_2);
	if (mlx_resize_image(g->sprite.win1, g->size_x * 1.2, \
		g->size_y * 0.6) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.win2, g->size_x * 1.2, \
		g->size_y * 0.6) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.win1, (g->data.e_x * WIDTH / \
		(g->data.width - 1)), (g->data.e_y * HEIGHT / g->data.height)) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.win1->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.win2, (g->data.e_x * WIDTH / \
		(g->data.width - 1)), (g->data.e_y * HEIGHT / g->data.height)) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.win2->instances->enabled = false;
}
