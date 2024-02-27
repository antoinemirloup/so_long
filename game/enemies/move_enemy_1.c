/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:25:54 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 12:02:16 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	enemy_1_up(t_game *g)
{
	if (g->a % 2 == 0)
	{
		g->data.map[g->n1_y - 1][g->n1_x] = 'Z';
		g->data.map[g->n1_y][g->n1_x] = '0';
	}
	if (g->sprite.enemy1 == g->sprite.enemy1a)
	{
		g->sprite.enemy1 = g->sprite.enemy1b;
		g->sprite.enemy1a->instances->enabled = false;
		g->sprite.enemy1b->instances->enabled = true;
		g->sprite.enemy1a->instances[0].y -= g->size_y / 2;
		g->sprite.enemy1b->instances[0].y -= g->size_y / 2;
		g->a++;
	}
	else if (g->sprite.enemy1 == g->sprite.enemy1b)
	{
		g->sprite.enemy1 = g->sprite.enemy1a;
		g->sprite.enemy1a->instances->enabled = true;
		g->sprite.enemy1b->instances->enabled = false;
		g->sprite.enemy1a->instances[0].y -= g->size_y / 2;
		g->sprite.enemy1b->instances[0].y -= g->size_y / 2;
		g->a++;
	}
}

void	enemy_1_down(t_game *g)
{
	if (g->a % 2 == 0)
	{
		g->data.map[g->n1_y + 1][g->n1_x] = 'Z';
		g->data.map[g->n1_y][g->n1_x] = '0';
	}
	if (g->sprite.enemy1 == g->sprite.enemy1a)
	{
		g->sprite.enemy1 = g->sprite.enemy1b;
		g->sprite.enemy1a->instances->enabled = false;
		g->sprite.enemy1b->instances->enabled = true;
		g->sprite.enemy1a->instances[0].y += g->size_y / 2;
		g->sprite.enemy1b->instances[0].y += g->size_y / 2;
		g->a++;
	}
	else if (g->sprite.enemy1 == g->sprite.enemy1b)
	{
		g->sprite.enemy1 = g->sprite.enemy1a;
		g->sprite.enemy1a->instances->enabled = true;
		g->sprite.enemy1b->instances->enabled = false;
		g->sprite.enemy1a->instances[0].y += g->size_y / 2;
		g->sprite.enemy1b->instances[0].y += g->size_y / 2;
		g->a++;
	}
}

void	move_enemy_1(t_game *g)
{
	if (g->dir_1 == 1)
	{
		g->e = 1;
		// printf("y: %d\n", g->n1_y);
		if (g->data.map[g->n1_y - 1][g->n1_x] != '0' && g->a % 2 == 0)
			g->dir_1 = 0;
		else
			enemy_1_up(g);
	}
	if (g->dir_1 == 0)
	{
		g->e = 1;
		// printf("y: %d\n", g->n1_y);
		if (g->data.map[g->n1_y + 1][g->n1_x] != '0' && g->a % 2 == 0)
			g->dir_1 = 1;
		else
			enemy_1_down(g);
	}
}
