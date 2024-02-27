/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:12:42 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 12:18:30 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_enemies(t_game *g)
{
	g->n1_x = round(g->sprite.enemy1a->instances[0].x * (float)(g->data.width - 1) / WIDTH);
	g->n1_y = round(g->sprite.enemy1a->instances[0].y * \
		(float)g->data.height / HEIGHT);
	g->n2_x = round(g->sprite.enemy2a->instances[0].x * (float)(g->data.width - 1) / WIDTH);
	g->n2_y = round(g->sprite.enemy2a->instances[0].y * \
		(float)g->data.height / HEIGHT);
	if (g->e == 0)
	{
		g->sprite.enemy1 = g->sprite.enemy1a;
		g->sprite.enemy2 = g->sprite.enemy2a;
	}
	move_enemy_1(g);
	move_enemy_2(g);
}
