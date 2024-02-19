/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/19 15:12:48 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_exit(t_game *g)
{
	if (g->c == 0)
	{
		mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * \
		WIDTH / g->data.width), (g->data.e_y * HEIGHT / g->data.height));
		g->data.map[g->data.e_y][g->data.e_x] = 'F';
	}
}

void	collectibles(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'Q')
	{
		g->b_q = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.battq);
	}
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'R')
	{
		g->b_r = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.battr);
	}
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'S')
	{
		g->b_s = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.batts);
	}
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
				{
					g->q_pos_x = g->c_pos_x;
					g->q_pos_y = g->c_pos_y;
				}
				else if (g->data.map[g->data.y][g->data.x] == 'R')
				{
					g->r_pos_x = g->c_pos_x;
					g->r_pos_y = g->c_pos_y;
				}
				else if (g->data.map[g->data.y][g->data.x] == 'S')
				{
					g->s_pos_x = g->c_pos_x;
					g->s_pos_y = g->c_pos_y;
				}
				g->i++;
			}
		}
	}
}

void	load_collectibles(t_game *g)
{
	g->c_size_y = (HEIGHT / g->data.height) / 1.2;
	g->c_size_x = g->w_size_y / 1.98;
	g->sprite.bat1 = mlx_load_png("assets/battery1.png");
	g->sprite.bat2 = mlx_load_png("assets/battery2.png");
	g->sprite.bat3 = mlx_load_png("assets/battery3.png");
	if (!g->sprite.bat1 || !g->sprite.bat2 || !g->sprite.bat3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
}

void	set_collectibles(t_game *g)
{
	g->sprite.batt1q = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt1r = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt1s = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2q = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt2r = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt2s = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3q = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	g->sprite.batt3r = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	g->sprite.batt3s = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	mlx_resize_image(g->sprite.batt1q, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt1r, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt1s, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt2q, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt2r, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt2s, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt3q, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt3r, g->c_size_x, g->c_size_y);
	mlx_resize_image(g->sprite.batt3s, g->c_size_x, g->c_size_y);
	place_collectibles(g);
}
