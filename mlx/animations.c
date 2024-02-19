/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:10:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/19 11:35:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	battq(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.battq);
	if (g->q == 0)
	{
		g->sprite.battq = g->sprite.batt1q;
		g->q++;
	}
	else if (g->q == 1)
	{
		g->sprite.battq = g->sprite.batt2q;
		g->q++;
	}
	else if (g->q == 2)
	{
		g->sprite.battq = g->sprite.batt3q;
		g->q++;
	}
	else if (g->q == 3)
	{
		g->sprite.battq = g->sprite.batt2q;
		g->q = 0;
	}
	mlx_image_to_window(g->mlx, g->sprite.battq, g->q_pos_x, g->q_pos_y);
}

void	battr(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.battr);
	if (g->r == 0)
	{
		g->sprite.battr = g->sprite.batt1r;
		g->r++;
	}
	else if (g->r == 1)
	{
		g->sprite.battr = g->sprite.batt2r;
		g->r++;
	}
	else if (g->r == 2)
	{
		g->sprite.battr = g->sprite.batt3r;
		g->r++;
	}
	else if (g->r == 3)
	{
		g->sprite.battr = g->sprite.batt2r;
		g->r = 0;
	}
	mlx_image_to_window(g->mlx, g->sprite.battr, g->r_pos_x, g->r_pos_y);
}

void	batts(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.batts);
	if (g->s == 0)
	{
		g->sprite.batts = g->sprite.batt1s;
		g->s++;
	}
	else if (g->s == 1)
	{
		g->sprite.batts = g->sprite.batt2s;
		g->s++;
	}
	else if (g->s == 2)
	{
		g->sprite.batts = g->sprite.batt3s;
		g->s++;
	}
	else if (g->s == 3)
	{
		g->sprite.batts = g->sprite.batt2s;
		g->s = 0;
	}
	mlx_image_to_window(g->mlx, g->sprite.batts, g->s_pos_x, g->s_pos_y);
}

void	refresh(t_game *g)
{
	set_collectibles(g);
	if (g->frame % 8 == 0 && g->b_q == 1)
		battq(g);
	if (g->frame % 8 == 0 && g->b_r == 1)
		battr(g);
	if (g->frame % 8 == 0 && g->b_s == 1)
		batts(g);
}
