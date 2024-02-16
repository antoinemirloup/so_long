/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:48:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 13:52:48 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *g)
{
	g->sprite.player->instances[0].y -= g->p_size_y;
	g->sprite.fo->instances[0].y -= g->p_size_y;
	g->count++;
}

void	move_down(t_game *g)
{
	g->sprite.player->instances[0].y += g->p_size_y;
	g->sprite.fo->instances[0].y += g->p_size_y;
	g->count++;
}

void	move_left(t_game *g)
{
	g->sprite.player->instances[0].x -= g->p_size_x;
	g->sprite.fo->instances[0].x -= g->p_size_x;
	g->count++;
}

void	move_rigth(t_game *g)
{
	g->sprite.player->instances[0].x += g->p_size_x;
	g->sprite.fo->instances[0].x += g->p_size_x;
	g->count++;
}