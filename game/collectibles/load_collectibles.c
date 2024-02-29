/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_collectibles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:31:30 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/29 13:31:00 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_collectibles(t_game *g)
{
	g->c_size_y = g->size_y / 1.2;
	g->c_size_x = g->size_y / 1.98;
	g->sprite.bat1 = mlx_load_png("assets/battery1.png");
	if (!g->sprite.bat1)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.bat2 = mlx_load_png("assets/battery2.png");
	if (!g->sprite.bat2)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.bat3 = mlx_load_png("assets/battery3.png");
	if (!g->sprite.bat3)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt1q = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2q = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3q = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	g->sprite.batt1r = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2r = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3r = mlx_texture_to_image(g->mlx, g->sprite.bat3);
	g->sprite.batt1s = mlx_texture_to_image(g->mlx, g->sprite.bat1);
	g->sprite.batt2s = mlx_texture_to_image(g->mlx, g->sprite.bat2);
	g->sprite.batt3s = mlx_texture_to_image(g->mlx, g->sprite.bat3);
}

void	resize_collectibles(t_game *g)
{
	if (mlx_resize_image(g->sprite.batt1q, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt2q, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt3q, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt1r, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt2r, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt3r, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt1s, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt2s, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.batt3s, g->c_size_x, g->c_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	coll1(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.batt1q, g->q_pos_x, \
		g->q_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt1q->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt2q, g->q_pos_x, \
		g->q_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt2q->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt3q, g->q_pos_x, \
		g->q_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt3q->instances->enabled = false;
}

void	coll2(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.batt1r, g->r_pos_x, \
		g->r_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt1r->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt2r, g->r_pos_x, \
		g->r_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt2r->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt3r, g->r_pos_x, \
		g->r_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt2r->instances->enabled = false;
}

void	coll3(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.batt1s, g->s_pos_x, \
		g->s_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt1s->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt2s, g->s_pos_x, \
		g->s_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt2s->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->sprite.batt3s, g->s_pos_x, \
		g->s_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.batt3s->instances->enabled = false;
}
