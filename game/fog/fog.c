/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	first_fog(t_game *g)
{
	g->sprite.fogg1->instances->enabled = true;
}

void	second_fog(t_game *g)
{
	g->sprite.fogg2->instances->enabled = true;
	g->sprite.fogg1->instances->enabled = false;
}

void	third_fog(t_game *g)
{
	g->sprite.fogg3->instances->enabled = true;
	g->sprite.fogg2->instances->enabled = false;
	g->sprite.fogg1->instances->enabled = false;
}

void	fourth_fog(t_game *g)
{
	g->sprite.fogg4->instances->enabled = true;
	g->sprite.fogg3->instances->enabled = false;
	g->sprite.fogg2->instances->enabled = false;
	g->sprite.fogg1->instances->enabled = false;
}

void	fog(t_game *g)
{
	if (g->c == g->c_tot)
		first_fog(g);
	else if (g->c == g->c_tot - 1)
		second_fog(g);
	else if (g->c == g->c_tot - 2)
		third_fog(g);
	else if (g->c == g->c_tot - 3)
		fourth_fog(g);
}
