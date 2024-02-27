/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:42 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 14:34:27 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_one_enemy(t_game *g)
{
	g->n1_x = round(g->sprite.enemy1a->instances[0].x * \
		(float)(g->data.width - 1) / WIDTH);
	g->n1_y = round(g->sprite.enemy1a->instances[0].y * \
		(float)g->data.height / HEIGHT);
	if (g->e == 0)
		g->sprite.enemy1 = g->sprite.enemy1a;
	move_enemy_1(g);
}

void	move_enemies(t_game *g)
{
	if (g->n_enemies == 1)
		move_one_enemy(g);
	if (g->n_enemies == 2)
	{
		g->n1_x = round(g->sprite.enemy1a->instances[0].x * \
			(float)(g->data.width - 1) / WIDTH);
		g->n1_y = round(g->sprite.enemy1a->instances[0].y * \
			(float)g->data.height / HEIGHT);
		g->n2_x = round(g->sprite.enemy2a->instances[0].x * \
			(float)(g->data.width - 1) / WIDTH);
		g->n2_y = round(g->sprite.enemy2a->instances[0].y * \
			(float)g->data.height / HEIGHT);
		if (g->e == 0)
		{
			g->sprite.enemy1 = g->sprite.enemy1a;
			g->sprite.enemy2 = g->sprite.enemy2a;
		}
		move_enemy_1(g);
		move_enemy_2(g);
	}
}

void	set_one_enemy(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1a, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1b, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}

void	set_two_enemies(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1a, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1b, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy2a, g->y_pos_x, \
	g->y_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy2b, g->y_pos_x, \
	g->y_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}
