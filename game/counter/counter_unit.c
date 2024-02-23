/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:37:22 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 15:19:34 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	resize_units(t_game *g)
{
	if (mlx_resize_image(g->co.u0, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u1, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u2, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u3, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u4, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u5, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u6, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u7, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u8, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.u9, WIDTH / (30), HEIGHT / 15) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	units_to_window(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->co.u2, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u2->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u3, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u3->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u4, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u4->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u5, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u5->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u6, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u6->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u7, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u7->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u8, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u8->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->co.u9, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u9->instances->enabled = false;
}

void	get_units(t_game *g)
{
	load_numbers(g);
	g->co.u0 = mlx_texture_to_image(g->mlx, g->co.zero);
	g->co.u1 = mlx_texture_to_image(g->mlx, g->co.one);
	g->co.u2 = mlx_texture_to_image(g->mlx, g->co.two);
	g->co.u3 = mlx_texture_to_image(g->mlx, g->co.three);
	g->co.u4 = mlx_texture_to_image(g->mlx, g->co.four);
	g->co.u5 = mlx_texture_to_image(g->mlx, g->co.five);
	g->co.u6 = mlx_texture_to_image(g->mlx, g->co.six);
	g->co.u7 = mlx_texture_to_image(g->mlx, g->co.seven);
	g->co.u8 = mlx_texture_to_image(g->mlx, g->co.eigth);
	g->co.u9 = mlx_texture_to_image(g->mlx, g->co.nine);
	resize_units(g);
	if (mlx_image_to_window(g->mlx, g->co.u0, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u0->instances->enabled = true;
	if (mlx_image_to_window(g->mlx, g->co.u1, WIDTH - 90, 20) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->co.u1->instances->enabled = false;
	units_to_window(g);
}

void	disable_units(t_game *g)
{
	g->co.u0->instances->enabled = false;
	g->co.u1->instances->enabled = false;
	g->co.u2->instances->enabled = false;
	g->co.u3->instances->enabled = false;
	g->co.u4->instances->enabled = false;
	g->co.u5->instances->enabled = false;
	g->co.u6->instances->enabled = false;
	g->co.u7->instances->enabled = false;
	g->co.u8->instances->enabled = false;
	g->co.u9->instances->enabled = false;	
}
