/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:15:45 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/21 14:12:56 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_death(t_game *g)
{
	g->d.black_screen = mlx_load_png("assets/black_screen.png");
	g->d.death1 = mlx_load_png("assets/death1.png");
	g->d.death2 = mlx_load_png("assets/death2.png");
	g->d.death3 = mlx_load_png("assets/death3.png");
	g->d.death4 = mlx_load_png("assets/death4.png");
	g->d.death5 = mlx_load_png("assets/death5.png");
	g->d.death6 = mlx_load_png("assets/death6.png");
	g->d.death7 = mlx_load_png("assets/death7.png");
	g->d.death8 = mlx_load_png("assets/death8.png");
	g->d.black = mlx_texture_to_image(g->mlx, g->d.black_screen);
	g->d.d[0] = mlx_texture_to_image(g->mlx, g->d.death1);
	g->d.d[1] = mlx_texture_to_image(g->mlx, g->d.death2);
	g->d.d[2] = mlx_texture_to_image(g->mlx, g->d.death3);
	g->d.d[3] = mlx_texture_to_image(g->mlx, g->d.death4);
	g->d.d[4] = mlx_texture_to_image(g->mlx, g->d.death5);
	g->d.d[5] = mlx_texture_to_image(g->mlx, g->d.death6);
	g->d.d[6] = mlx_texture_to_image(g->mlx, g->d.death7);
	g->d.d[7] = mlx_texture_to_image(g->mlx, g->d.death8);
	mlx_image_to_window(g->mlx, g->d.black, 0, 0);
	g->d.black->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[0], 836, 362);
	g->d.d[0]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[1], 836, 362);
	g->d.d[1]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[2], 836, 362);
	g->d.d[2]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[3], 836, 362);
	g->d.d[3]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[4], 836, 362);
	g->d.d[4]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[5], 836, 362);
	g->d.d[5]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[6], 836, 362);
	g->d.d[6]->instances->enabled = false;
	mlx_image_to_window(g->mlx, g->d.d[7], 836, 362);
	g->d.d[7]->instances->enabled = false;
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
	{
		g->alive = 0;
	}
}
