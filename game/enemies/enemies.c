/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:18 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 12:57:39 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	coord_enemy_z(t_game *g)
{
	g->z_pos_x = g->n_pos_x;
	g->z_pos_y = g->n_pos_y;
}

void	coord_enemy_y(t_game *g)
{
	g->y_pos_x = g->n_pos_x;
	g->y_pos_y = g->n_pos_y;
}

void	place_ennemies(t_game *g)
{
	g->i = 0;
	g->data.y = -1;
	while (++g->data.y < g->data.height)
	{
		g->data.x = -1;
		while (++g->data.x < g->data.width)
		{
			if (g->data.map[g->data.y][g->data.x] == 'N')
			{
				g->n_pos_x = round(g->data.x * \
					(WIDTH / (float)(g->data.width - 1)));
				g->n_pos_y = round(g->data.y * \
					(HEIGHT / (float)(g->data.height)));
				g->data.map[g->data.y][g->data.x] = 'Z' - g->i;
				if (g->data.map[g->data.y][g->data.x] == 'Z')
					coord_enemy_z(g);
				else if (g->data.map[g->data.y][g->data.x] == 'Y')
					coord_enemy_y(g);
				g->i++;
			}
		}
	}
}

void	resize_enemies(t_game *g)
{
	if (mlx_resize_image(g->sprite.enemy1a, g->size_x, \
		g->size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy1b, g->size_x, \
		g->size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy2a, g->size_x, \
		g->size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy2b, g->size_x, \
		g->size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	set_enemies(t_game *g)
{
	place_ennemies(g);
	g->sprite.enemya = mlx_load_png("assets/alien1.png");
	if (!g->sprite.enemya)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.enemyb = mlx_load_png("assets/alien2.png");
	if (!g->sprite.enemyb)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.enemy1a = mlx_texture_to_image(g->mlx, g->sprite.enemya);
	g->sprite.enemy1b = mlx_texture_to_image(g->mlx, g->sprite.enemyb);
	g->sprite.enemy2a = mlx_texture_to_image(g->mlx, g->sprite.enemya);
	g->sprite.enemy2b = mlx_texture_to_image(g->mlx, g->sprite.enemyb);
	resize_enemies(g);
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
