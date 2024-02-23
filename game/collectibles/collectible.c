/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:53:47 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 14:22:35 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	collectibles(t_game *g)
{
	delete_coll1(g);
	delete_coll2(g);
	delete_coll3(g);
}

void	place_r(t_game *g)
{
	g->r_pos_x = g->c_pos_x;
	g->r_pos_y = g->c_pos_y;
}

void	place_s(t_game *g)
{
	g->s_pos_x = g->c_pos_x;
	g->s_pos_y = g->c_pos_y;
}

void	place_collectibles(t_game *g)
{
	g->i = 0;
	g->data.y = -1;
	while (++g->data.y < g->data.height)
	{
		g->data.x = -1;
		while (++g->data.x < g->data.width)
		{
			if (g->data.map[g->data.y][g->data.x] == 'C')
			{
				g->c_pos_x = g->data.x * (WIDTH / (float)(g->data.width - 1));
				g->c_pos_y = g->data.y * (HEIGHT / (float)(g->data.height));
				g->data.map[g->data.y][g->data.x] = 'Q' + g->i;
				if (g->data.map[g->data.y][g->data.x] == 'Q')
				{
					g->q_pos_x = g->c_pos_x;
					g->q_pos_y = g->c_pos_y;
				}
				else if (g->data.map[g->data.y][g->data.x] == 'R')
					place_r(g);
				else if (g->data.map[g->data.y][g->data.x] == 'S')
					place_s(g);
				g->i++;
			}
		}
	}
}

void	set_collectibles(t_game *g)
{
	place_collectibles(g);
	load_collectibles(g);
	resize_collectibles(g);
	coll1(g);
	coll2(g);
	coll3(g);
}
