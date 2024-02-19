/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_fog(t_game *g)
{
	g->sprite.fog = mlx_load_png("assets/fog.png");
	if (!g->sprite.fog)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
}

void	first_fog(t_game *g)
{
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	second_fog(t_game *g)
{
	g->c--;
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 6000, 3000);
	if (g->c == 0)
	{
		mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * WIDTH / \
		g->data.width), (g->data.e_y * HEIGHT / g->data.height));
		g->data.map[g->data.e_y][g->data.e_x] = 'F';
	}
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(3000 - g->p_size_x / 2)), (g->p_pos_y - (1500 - g->p_size_y / 2)));
}

void	third_fog(t_game *g)
{
	g->c--;
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 8000, 4000);
	if (g->c == 0)
	{
		mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * WIDTH / \
			g->data.width), (g->data.e_y * HEIGHT / g->data.height));
		g->data.map[g->data.e_y][g->data.e_x] = 'F';
	}
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(4000 - g->p_size_x / 2)), (g->p_pos_y - (2000 - g->p_size_y / 2)));
}

void	fourth_fog(t_game *g)
{
	g->c--;
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 10000, 5000);
	if (g->c == 0)
	{
		mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * WIDTH / \
			g->data.width), (g->data.e_y * HEIGHT / g->data.height));
		g->data.map[g->data.e_y][g->data.e_x] = 'F';
	}
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(5000 - g->p_size_x / 2)), (g->p_pos_y - (2500 - g->p_size_y / 2)));
}

void	fog(t_game *g)
{
	g->c = count_c(&g->data, 'Q') + count_c(&g->data, 'R') + \
		count_c(&g->data, 'S');
	if (g->c == g->c_tot)
		first_fog(g);
	else if (g->c == g->c_tot - 1)
		second_fog(g);
	else if (g->c == g->c_tot - 2)
		third_fog(g);
	else if (g->c == g->c_tot - 3)
		fourth_fog(g);
}
