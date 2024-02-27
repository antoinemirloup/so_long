/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:48:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 12:19:46 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *g)
{
	printf("p_x: %d | p_y: %d\n", g->p_coord_x, g->p_coord_y);
	g->sprite.player_left->instances[0].y -= g->size_y;
	g->sprite.player_right->instances[0].y -= g->size_y;
	g->sprite.fogg1->instances[0].y -= g->size_y;
	g->sprite.fogg2->instances[0].y -= g->size_y;
	g->sprite.fogg3->instances[0].y -= g->size_y;
	g->sprite.fogg4->instances[0].y -= g->size_y;
	g->count++;
}

void	move_down(t_game *g)
{
	printf("p_x: %d | p_y: %d\n", g->p_coord_x, g->p_coord_y);
	g->sprite.player_left->instances[0].y += g->size_y;
	g->sprite.player_right->instances[0].y += g->size_y;
	g->sprite.fogg1->instances[0].y += g->size_y;
	g->sprite.fogg2->instances[0].y += g->size_y;
	g->sprite.fogg3->instances[0].y += g->size_y;
	g->sprite.fogg4->instances[0].y += g->size_y;
	g->count++;
}

void	move_left(t_game *g)
{
	printf("p_x: %d | p_y: %d\n", g->p_coord_x, g->p_coord_y);
	g->sprite.player_left->instances->enabled = true;
	g->sprite.player_right->instances->enabled = false;
	g->sprite.player_left->instances[0].x -= g->size_x;
	g->sprite.player_right->instances[0].x -= g->size_x;
	g->sprite.fogg1->instances[0].x -= g->size_x;
	g->sprite.fogg2->instances[0].x -= g->size_x;
	g->sprite.fogg3->instances[0].x -= g->size_x;
	g->sprite.fogg4->instances[0].x -= g->size_x;
	g->count++;
}

void	move_rigth(t_game *g)
{
	printf("p_x: %d | p_y: %d\n", g->p_coord_x, g->p_coord_y);
	g->sprite.player_left->instances->enabled = false;
	g->sprite.player_right->instances->enabled = true;
	g->sprite.player_left->instances[0].x += g->size_x;
	g->sprite.player_right->instances[0].x += g->size_x;
	g->sprite.fogg1->instances[0].x += g->size_x;
	g->sprite.fogg2->instances[0].x += g->size_x;
	g->sprite.fogg3->instances[0].x += g->size_x;
	g->sprite.fogg4->instances[0].x += g->size_x;
	g->count++;
}
