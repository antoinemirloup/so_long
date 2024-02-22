/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_collectibles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:40 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/22 14:34:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_coll1(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'Q')
	{
		g->b_q = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.batt1q);
		mlx_delete_image(g->mlx, g->sprite.batt2q);
		mlx_delete_image(g->mlx, g->sprite.batt3q);
	}
}

void	delete_coll2(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'R')
	{
		g->b_r = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.batt1r);
		mlx_delete_image(g->mlx, g->sprite.batt2r);
		mlx_delete_image(g->mlx, g->sprite.batt3r);
	}
}

void	delete_coll3(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'S')
	{
		g->b_s = 0;
		g->c--;
		g->data.map[g->p_coord_y][g->p_coord_x] = '0';
		place_exit(g);
		mlx_delete_image(g->mlx, g->sprite.batt1s);
		mlx_delete_image(g->mlx, g->sprite.batt2s);
		mlx_delete_image(g->mlx, g->sprite.batt3s);
	}
}
