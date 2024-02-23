/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:15:45 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 09:59:28 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	images_on_window(t_game *g)
{
	g->d.d[0]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[1], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[1]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[2], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[2]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[3], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[3]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[4], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[4]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[5], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[5]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[6], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[6]->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[7], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.d[7]->instances->enabled = false;
}

void	set_death(t_game *g)
{
	load_death(g);
	if (mlx_image_to_window(g->mlx, g->d.black, 0, 0) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	g->d.black->instances->enabled = false;
	if (mlx_image_to_window(g->mlx, g->d.d[0], 836, 362) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	images_on_window(g);
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
}

void	death(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'Z'
		|| g->data.map[g->p_coord_y][g->p_coord_x] == 'Y')
		g->alive = 0;
}
