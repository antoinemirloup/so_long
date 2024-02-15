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
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->data.p_x * WIDTH / \
		(g->data.width - 1)) - (2000 - g->p_size_x / 2), \
		(g->data.p_y * HEIGHT / g->data.height) - (1000 - g->p_size_y / 2));
}

void	first_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 6000, 3000);
	if (g->c_tot - g->c == 0)
		exit_game(g);
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(3000 - g->p_size_x / 2)), (g->p_pos_y - (1500 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c--;
}

void	second_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 8000, 4000);
	if (g->c_tot - g->c == 0)
		exit_game(g);
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(4000 - g->p_size_x / 2)), (g->p_pos_y - (2000 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c--;
}

void	third_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fo);
	g->sprite.fo = mlx_texture_to_image(g->mlx, g->sprite.fog);
	mlx_resize_image(g->sprite.fo, 10000, 5000);
	if (g->c_tot - g->c== 0)
		exit_game(g);
	mlx_image_to_window(g->mlx, g->sprite.fo, (g->p_pos_x - \
	(5000 - g->p_size_x / 2)), (g->p_pos_y - (2500 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c--;
}

void	fog(t_game *g)
{
	g->c = count_c(&g->data, 'C');
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'C')
	{
		if (g->c == g->c_tot)
			first_fog(g);
		else if (g->c == g->c_tot - 1)
			second_fog(g);
		else if (g->c == g->c_tot - 2)
			third_fog(g);
	}
}
