/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:08:11 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/26 09:59:10 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_exit(t_game *g)
{
	if (g->c == 0)
	{
		g->sprite.exit_nest->instances->enabled = true;
		if (g->c_tot == 3)
			g->sprite.fogg4->instances->enabled = true;
		else if (g->c_tot == 2)
			g->sprite.fogg3->instances->enabled = true;
		else if (g->c_tot == 1)
			g->sprite.fogg2->instances->enabled = true;
		if (g->c_tot == 0)
			g->sprite.fogg1->instances->enabled = true;
		g->data.map[g->data.e_y][g->data.e_x] = 'F';
	}
}

void	disp_result(t_game *g)
{
	if (mlx_resize_image(g->co.result[0], 200, 200) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.result[1], 200, 200) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->co.result[2], 200, 200) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->co.result[0], WIDTH / 2 + 100, \
		HEIGHT / 2 + 100) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->co.result[1], WIDTH / 2 - 100, \
		HEIGHT / 2 + 100) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->co.result[2], WIDTH / 2 - 300, \
		HEIGHT / 2 + 100) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}

void	exit_game(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'F')
	{
		g->success = 1;
		if (mlx_image_to_window(g->mlx, g->sprite.succes, WIDTH / 2 - 300, \
			HEIGHT / 2 - 500) == -1)
			exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
		mlx_delete_image(g->mlx, g->sprite.fogg1);
		mlx_delete_image(g->mlx, g->sprite.fogg2);
		mlx_delete_image(g->mlx, g->sprite.fogg3);
		mlx_delete_image(g->mlx, g->sprite.fogg4);
		g->co.result[0] = mlx_texture_to_image(g->mlx, result_unit(g));
		g->co.result[1] = mlx_texture_to_image(g->mlx, result_ten(g));
		g->co.result[2] = mlx_texture_to_image(g->mlx, result_hundred(g));
		disp_result(g);
	}
}

void	set_exit(t_game *g)
{
	g->sprite.nest = mlx_load_png("assets/nest.png");
	if (!g->sprite.nest)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.exit_nest = mlx_texture_to_image(g->mlx, g->sprite.nest);
	if (mlx_resize_image(g->sprite.exit_nest, g->w_size_x, \
		g->w_size_y / 1.2) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * \
		WIDTH / (g->data.width - 1)), (g->data.e_y * \
		HEIGHT / g->data.height)) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.exit_nest->instances->enabled = false;
	g->sprite.success = mlx_load_png("assets/success.png");
	if (!g->sprite.success)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.succes = mlx_texture_to_image(g->mlx, g->sprite.success);
	if (mlx_resize_image(g->sprite.succes, 600, 600) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}
