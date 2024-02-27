/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:15:45 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 16:35:39 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	images_on_window(t_game *g, int x, int y)
{
	if (mlx_image_to_window(g->mlx, g->d.d[0], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[0]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[1], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[1]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[2], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[2]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[3], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[3]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[4], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[4]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[5], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[5]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[6], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[6]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[7], x, y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[7]->instances->enabled = false;
}

void	set_death(t_game *g)
{
	int	x;
	int	y;

	x = (WIDTH / 2) - (327 * WIDTH / 2000) / 2;
	y = HEIGHT - (638 * HEIGHT / 1000);
	load_death(g);
	if (mlx_image_to_window(g->mlx, g->d.black, 0, 0) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.black->instances->enabled = false;
	images_on_window(g, x, y);
}

void	animate_death(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fogg1);
	mlx_delete_image(g->mlx, g->sprite.fogg2);
	mlx_delete_image(g->mlx, g->sprite.fogg3);
	mlx_delete_image(g->mlx, g->sprite.fogg4);
	g->d.black->instances->enabled = true;
	g->d.d[g->d.i]->instances->enabled = true;
	if (g->d.i > 0)
		g->d.d[g->d.i - 1]->instances->enabled = false;
	g->d.i++;
	if (g->d.i == 8)
		mlx_close_window(g->mlx);
}

void	death(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'Z'
		|| g->data.map[g->p_coord_y][g->p_coord_x] == 'Y')
		g->alive = 0;
}
