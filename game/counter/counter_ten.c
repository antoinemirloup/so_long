/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_ten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:12:40 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 16:41:29 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	resize_ten(t_game *g)
{
	if (mlx_resize_image(g->co.t0, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t1, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t2, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t3, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t4, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t5, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t6, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t7, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t8, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.t9, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	ten_to_window(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->co.t2, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t2->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t3, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t3->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t4, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t4->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t5, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t5->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t6, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t6->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t7, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t7->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t8, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t8->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.t9, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t9->instances->enabled = false;
}

void	get_ten(t_game *g)
{
	g->co.t0 = mlx_texture_to_image(g->mlx, g->co.zero);
	g->co.t1 = mlx_texture_to_image(g->mlx, g->co.one);
	g->co.t2 = mlx_texture_to_image(g->mlx, g->co.two);
	g->co.t3 = mlx_texture_to_image(g->mlx, g->co.three);
	g->co.t4 = mlx_texture_to_image(g->mlx, g->co.four);
	g->co.t5 = mlx_texture_to_image(g->mlx, g->co.five);
	g->co.t6 = mlx_texture_to_image(g->mlx, g->co.six);
	g->co.t7 = mlx_texture_to_image(g->mlx, g->co.seven);
	g->co.t8 = mlx_texture_to_image(g->mlx, g->co.eigth);
	g->co.t9 = mlx_texture_to_image(g->mlx, g->co.nine);
	resize_ten(g);
	if (mlx_image_to_window(g->mlx, g->co.t0, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t0->instances->enabled = true;
	if (mlx_image_to_window(g->mlx, g->co.t1, WIDTH - 140, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.t1->instances->enabled = false;
	ten_to_window(g);
}

void	disable_ten(t_game *g)
{
	g->co.t0->instances->enabled = false;
	g->co.t1->instances->enabled = false;
	g->co.t2->instances->enabled = false;
	g->co.t3->instances->enabled = false;
	g->co.t4->instances->enabled = false;
	g->co.t5->instances->enabled = false;
	g->co.t6->instances->enabled = false;
	g->co.t7->instances->enabled = false;
	g->co.t8->instances->enabled = false;
	g->co.t9->instances->enabled = false;
}
