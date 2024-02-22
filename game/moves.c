/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:48:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/22 17:16:47 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *g)
{
	g->sprite.player->instances[0].y -= g->p_size_y;
	g->sprite.p_l[0]->instances[0].y -= g->p_size_y;
	g->sprite.p_l[1]->instances[0].y -= g->p_size_y;
	g->sprite.p_l[2]->instances[0].y -= g->p_size_y;
	g->sprite.p_l[3]->instances[0].y -= g->p_size_y;
	g->sprite.p_r[0]->instances[0].y -= g->p_size_y;
	g->sprite.p_r[1]->instances[0].y -= g->p_size_y;
	g->sprite.p_r[1]->instances[0].y -= g->p_size_y;
	g->sprite.p_r[3]->instances[0].y -= g->p_size_y;
	g->sprite.fogg1->instances[0].y -= g->p_size_y;
	g->sprite.fogg2->instances[0].y -= g->p_size_y;
	g->sprite.fogg3->instances[0].y -= g->p_size_y;
	g->sprite.fogg4->instances[0].y -= g->p_size_y;
	g->count++;
}

void	move_down(t_game *g)
{
	g->sprite.player->instances[0].y += g->p_size_y;
	g->sprite.p_l[0]->instances[0].y += g->p_size_y;
	g->sprite.p_l[1]->instances[0].y += g->p_size_y;
	g->sprite.p_l[2]->instances[0].y += g->p_size_y;
	g->sprite.p_l[3]->instances[0].y += g->p_size_y;
	g->sprite.p_r[0]->instances[0].y += g->p_size_y;
	g->sprite.p_r[1]->instances[0].y += g->p_size_y;
	g->sprite.p_r[2]->instances[0].y += g->p_size_y;
	g->sprite.p_r[3]->instances[0].y += g->p_size_y;
	g->sprite.fogg1->instances[0].y += g->p_size_y;
	g->sprite.fogg2->instances[0].y += g->p_size_y;
	g->sprite.fogg3->instances[0].y += g->p_size_y;
	g->sprite.fogg4->instances[0].y += g->p_size_y;
	g->count++;
}

void	move_left(t_game *g)
{
	g->moving = 1;
	g->sprite.player->instances[0].x -= g->p_size_x;
	g->sprite.p_l[0]->instances[0].x -= g->p_size_x;
	g->sprite.p_l[1]->instances[0].x -= g->p_size_x;
	g->sprite.p_l[2]->instances[0].x -= g->p_size_x;
	g->sprite.p_l[3]->instances[0].x -= g->p_size_x;
	g->sprite.p_r[0]->instances[0].x -= g->p_size_x;
	g->sprite.p_r[1]->instances[0].x -= g->p_size_x;
	g->sprite.p_r[2]->instances[0].x -= g->p_size_x;
	g->sprite.p_r[3]->instances[0].x -= g->p_size_x;
	g->sprite.fogg1->instances[0].x -= g->p_size_x;
	g->sprite.fogg2->instances[0].x -= g->p_size_x;
	g->sprite.fogg3->instances[0].x -= g->p_size_x;
	g->sprite.fogg4->instances[0].x -= g->p_size_x;
	g->count++;
}

void	move_rigth(t_game *g)
{
	g->sprite.player->instances[0].x += g->p_size_x;
	g->sprite.p_l[0]->instances[0].x += g->p_size_x;
	g->sprite.p_l[1]->instances[0].x += g->p_size_x;
	g->sprite.p_l[2]->instances[0].x += g->p_size_x;
	g->sprite.p_l[3]->instances[0].x += g->p_size_x;
	g->sprite.p_r[0]->instances[0].x += g->p_size_x;
	g->sprite.p_r[1]->instances[0].x += g->p_size_x;
	g->sprite.p_r[2]->instances[0].x += g->p_size_x;
	g->sprite.p_r[3]->instances[0].x += g->p_size_x;
	g->sprite.fogg1->instances[0].x += g->p_size_x;
	g->sprite.fogg2->instances[0].x += g->p_size_x;
	g->sprite.fogg3->instances[0].x += g->p_size_x;
	g->sprite.fogg4->instances[0].x += g->p_size_x;
	g->count++;
}
