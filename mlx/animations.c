/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:10:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/20 16:54:12 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	battq(t_game *g)
{
	if (g->q == 0)
	{
		g->sprite.batt1q->instances->enabled = true;
		g->sprite.batt2q->instances->enabled = false;
		g->q++;
	}
	else if (g->q == 1)
	{
		g->sprite.batt2q->instances->enabled = true;
		g->sprite.batt1q->instances->enabled = false;
		g->q++;
	}
	else if (g->q == 2)
	{
		g->sprite.batt3q->instances->enabled = true;
		g->sprite.batt2q->instances->enabled = false;
		g->q++;
	}
	else if (g->q == 3)
	{
		g->sprite.batt2q->instances->enabled = true;
		g->sprite.batt3q->instances->enabled = false;
		g->q = 0;
	}
}

void	battr(t_game *g)
{
	if (g->r == 0)
	{
		g->sprite.batt1r->instances->enabled = true;
		g->sprite.batt2r->instances->enabled = false;
		g->r++;
	}
	else if (g->r == 1)
	{
		g->sprite.batt2r->instances->enabled = true;
		g->sprite.batt1r->instances->enabled = false;
		g->r++;
	}
	else if (g->r == 2)
	{
		g->sprite.batt3r->instances->enabled = true;
		g->sprite.batt2r->instances->enabled = false;
		g->r++;
	}
	else if (g->r == 3)
	{
		g->sprite.batt2r->instances->enabled = true;
		g->sprite.batt3r->instances->enabled = false;
		g->r = 0;
	}
}

void	batts(t_game *g)
{
	if (g->s == 0)
	{
		g->sprite.batt1s->instances->enabled = true;
		g->sprite.batt2s->instances->enabled = false;
		g->s++;
	}
	else if (g->s == 1)
	{
		g->sprite.batt2s->instances->enabled = true;
		g->sprite.batt1s->instances->enabled = false;
		g->s++;
	}
	else if (g->s == 2)
	{
		g->sprite.batt3s->instances->enabled = true;
		g->sprite.batt2s->instances->enabled = false;
		g->s++;
	}
	else if (g->s == 3)
	{
		g->sprite.batt2s->instances->enabled = true;
		g->sprite.batt3s->instances->enabled = false;
		g->s = 0;
	}
}

void	refresh(t_game *g)
{
	if (g->frame % 10 == 0 && g->b_q == 1)
		battq(g);
	if (g->frame % 10 == 0 && g->b_r == 1)
		battr(g);
	if (g->frame % 10 == 0 && g->b_s == 1)
		batts(g);
	if (g->frame % 8 == 0)
		move_enemies(g);
	if (g->frame % 8 == 0 && g->alive == 0)
		animate_death(g);
}
