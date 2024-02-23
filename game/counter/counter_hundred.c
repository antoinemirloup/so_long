/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:13:40 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 15:21:50 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	resize_hundred(t_game *g)
{
	if (mlx_resize_image(g->co.h0, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h1, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h2, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h3, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h4, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h5, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h6, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h7, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h8, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.h9, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	hundred_to_window(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->co.h2, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h2->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h3, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h3->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h4, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h4->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h5, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h5->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h6, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h6->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h7, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h7->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h8, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h8->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.h9, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h9->instances->enabled = false;
}

void	get_hundred(t_game *g)
{
	load_numbers(g);
	g->co.h0 = mlx_texture_to_image(g->mlx, g->co.zero);
	g->co.h1 = mlx_texture_to_image(g->mlx, g->co.one);
	g->co.h2 = mlx_texture_to_image(g->mlx, g->co.two);
	g->co.h3 = mlx_texture_to_image(g->mlx, g->co.three);
	g->co.h4 = mlx_texture_to_image(g->mlx, g->co.four);
	g->co.h5 = mlx_texture_to_image(g->mlx, g->co.five);
	g->co.h6 = mlx_texture_to_image(g->mlx, g->co.six);
	g->co.h7 = mlx_texture_to_image(g->mlx, g->co.seven);
	g->co.h8 = mlx_texture_to_image(g->mlx, g->co.eigth);
	g->co.h9 = mlx_texture_to_image(g->mlx, g->co.nine);
	resize_hundred(g);
	if (mlx_image_to_window(g->mlx, g->co.h0, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h0->instances->enabled = true;
	if (mlx_image_to_window(g->mlx, g->co.h1, WIDTH - 190, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.h1->instances->enabled = false;
	hundred_to_window(g);
}

void	disable_hundred(t_game *g)
{
	g->co.h0->instances->enabled = false;
	g->co.h1->instances->enabled = false;
	g->co.h2->instances->enabled = false;
	g->co.h3->instances->enabled = false;
	g->co.h4->instances->enabled = false;
	g->co.h5->instances->enabled = false;
	g->co.h6->instances->enabled = false;
	g->co.h7->instances->enabled = false;
	g->co.h8->instances->enabled = false;
	g->co.h9->instances->enabled = false;	
}
