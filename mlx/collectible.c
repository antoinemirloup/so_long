/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 13:45:14 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collectibles(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'Q')
		mlx_delete_image(g->mlx, g->sprite.batt1q);
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'R')
		mlx_delete_image(g->mlx, g->sprite.batt1r);
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'S')
		mlx_delete_image(g->mlx, g->sprite.batt1s);
}

void	place_collectibles(t_game *g)
{
	g->i = 0;
	g->data.y = -1;
	while (++g->data.y < g->data.height)
	{
		g->data.x = -1;
		while (++g->data.x < g->data.width)
		{
			if (g->data.map[g->data.y][g->data.x] == 'C')
			{
				g->c_pos_x = g->data.x * (WIDTH / (float)(g->data.width - 1));
				g->c_pos_y = g->data.y * (HEIGHT / (float)(g->data.height));
				g->data.map[g->data.y][g->data.x] = 'Q' + g->i;
				if (g->data.map[g->data.y][g->data.x] == 'Q')
					mlx_image_to_window(g->mlx, g->sprite.batt1q, g->c_pos_x, \
						g->c_pos_y);
				else if (g->data.map[g->data.y][g->data.x] == 'R')
					mlx_image_to_window(g->mlx, g->sprite.batt1r, g->c_pos_x, \
						g->c_pos_y);
				else if (g->data.map[g->data.y][g->data.x] == 'S')
					mlx_image_to_window(g->mlx, g->sprite.batt1s, g->c_pos_x, \
						g->c_pos_y);
				g->i++;
			}
		}
	}
}

void	set_collectibles(t_game *g)
{
	g->c_size_y = (HEIGHT / g->data.height) / 1.2;
	g->c_size_x = g->w_size_y / 1.98;
	g->sprite.bat1 = mlx_load_png("assets/battery1.png");
	g->sprite.bat2 = mlx_load_png("assets/battery2.png");
	g->sprite.bat3 = mlx_load_png("assets/battery3.png");
	if (!g->sprite.bat1 || !g->sprite.bat2 || !g->sprite.bat3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.batt1q = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt1r = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt1s = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2 = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3 = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	mlx_resize_image(g->sprite.batt1q, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt1r, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt1s, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt2, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt3, g->c_size_x, g->c_size_y);
	place_collectibles(g);
}
