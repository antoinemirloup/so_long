/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 10:13:43 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loop_collectibles(t_game *g)
{
	while (g->sprite.batt)
	{
		mlx_delete_image(g->mlx, g->sprite.batt1);
		mlx_image_to_window(g->mlx, g->sprite.batt2, g->c_pos_x, g->c_pos_y);
		mlx_delete_image(g->mlx, g->sprite.batt2);
		mlx_image_to_window(g->mlx, g->sprite.batt3, g->c_pos_x, g->c_pos_y);
		mlx_delete_image(g->mlx, g->sprite.batt3);
		mlx_image_to_window(g->mlx, g->sprite.batt2, g->c_pos_x, g->c_pos_y);
		mlx_delete_image(g->mlx, g->sprite.batt2);
		mlx_image_to_window(g->mlx, g->sprite.batt1, g->c_pos_x, g->c_pos_y);
	}
}

void	set_collectibles(t_game *g)
{
	g->data.y = 0;
	while (g->data.y < g->data.height)
	{
		g->data.x = 0;
		while (g->data.x < g->data.width)
		{
			if (g->data.map[g->data.y][g->data.x] == 'C')
			{
				g->c_pos_x = g->data.x * (WIDTH / (float)(g->data.width - 1));
				g->c_pos_y = g->data.y * (HEIGHT / (float)(g->data.height));
				mlx_image_to_window(g->mlx, g->sprite.batt1, g->c_pos_x, \
					g->c_pos_y);
			}
			g->data.x++;
		}
		g->data.y++;
	}
}

void	collectibles(t_game *g)
{
	g->c_size_y = (HEIGHT / g->data.height) / 1.2;
	g->c_size_x = g->w_size_y / 1.98;
	g->sprite.bat1 = mlx_load_png("assets/battery1.png");
	g->sprite.bat2 = mlx_load_png("assets/battery2.png");
	g->sprite.bat3 = mlx_load_png("assets/battery3.png");
	if (!g->sprite.bat1 || !g->sprite.bat2 || !g->sprite.bat3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.batt1 = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2 = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3 = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	mlx_resize_image(g->sprite.batt1, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt2, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt3, g->c_size_x, g->c_size_y);
	set_collectibles(g);
}
