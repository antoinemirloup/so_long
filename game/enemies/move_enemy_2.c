/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:50 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 12:02:23 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	enemy_2_up(t_game *g)
{
	if (g->b % 2 == 0)
	{
		g->data.map[g->n2_y - 1][g->n2_x] = 'Z';
		g->data.map[g->n2_y][g->n2_x] = '0';
	}
	if (g->sprite.enemy2 == g->sprite.enemy2a)
	{
		g->sprite.enemy2 = g->sprite.enemy2b;
		g->sprite.enemy2a->instances->enabled = false;
		g->sprite.enemy2b->instances->enabled = true;
		g->sprite.enemy2a->instances[0].y -= g->size_y / 2;
		g->sprite.enemy2b->instances[0].y -= g->size_y / 2;
		g->b++;
	}
	else if (g->sprite.enemy2 == g->sprite.enemy2b)
	{
		g->sprite.enemy2 = g->sprite.enemy2a;
		g->sprite.enemy2a->instances->enabled = true;
		g->sprite.enemy2b->instances->enabled = false;
		g->sprite.enemy2a->instances[0].y -= g->size_y / 2;
		g->sprite.enemy2b->instances[0].y -= g->size_y / 2;
		g->b++;
	}
}

void	enemy_2_down(t_game *g)
{
	if (g->b % 2 == 0)
	{
		g->data.map[g->n2_y + 1][g->n2_x] = 'Z';
		g->data.map[g->n2_y][g->n2_x] = '0';
	}
	if (g->sprite.enemy2 == g->sprite.enemy2a)
	{
		g->sprite.enemy2 = g->sprite.enemy2b;
		g->sprite.enemy2a->instances->enabled = false;
		g->sprite.enemy2b->instances->enabled = true;
		g->sprite.enemy2a->instances[0].y += g->size_y / 2;
		g->sprite.enemy2b->instances[0].y += g->size_y / 2;
		g->b++;
	}
	else if (g->sprite.enemy2 == g->sprite.enemy2b)
	{
		g->sprite.enemy2 = g->sprite.enemy2a;
		g->sprite.enemy2a->instances->enabled = true;
		g->sprite.enemy2b->instances->enabled = false;
		g->sprite.enemy2a->instances[0].y += g->size_y / 2;
		g->sprite.enemy2b->instances[0].y += g->size_y / 2;
		g->b++;
	}
}

void	move_enemy_2(t_game *g)
{
	if (g->dir_2 == 1)
	{
		g->e = 1;
		if (g->data.map[g->n2_y - 1][g->n2_x] != '0' && g->b % 2 == 0)
			g->dir_2 = 0;
		else
			enemy_2_up(g);
	}
	if (g->dir_2 == 0)
	{
		g->e = 1;
		if (g->data.map[g->n2_y + 1][g->n2_x] != '0' && g->b % 2 == 0)
			g->dir_2 = 1;
		else
			enemy_2_down(g);
	}
}
