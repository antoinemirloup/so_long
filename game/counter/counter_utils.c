/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:23:56 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 15:26:53 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	disp_unit(t_game *g)
{
	if (g->count % 10 == 0)
		g->co.u0->instances->enabled = true;
	if (g->count % 10 == 1)
		g->co.u1->instances->enabled = true;
	if (g->count % 10 == 2)
		g->co.u2->instances->enabled = true;
	if (g->count % 10 == 3)
		g->co.u3->instances->enabled = true;
	if (g->count % 10 == 4)
		g->co.u4->instances->enabled = true;
	if (g->count % 10 == 5)
		g->co.u5->instances->enabled = true;
	if (g->count % 10 == 6)
		g->co.u6->instances->enabled = true;
	if (g->count % 10 == 7)
		g->co.u7->instances->enabled = true;
	if (g->count % 10 == 8)
		g->co.u8->instances->enabled = true;
	if (g->count % 10 == 9)
		g->co.u9->instances->enabled = true;
}

void	disp_ten(t_game *g)
{
	if ((g->count / 10) % 10 == 0)
		g->co.t0->instances->enabled = true;
	if ((g->count / 10) % 10 == 1)
		g->co.t1->instances->enabled = true;
	if ((g->count / 10) % 10 == 2)
		g->co.t2->instances->enabled = true;
	if ((g->count / 10) % 10 == 3)
		g->co.t3->instances->enabled = true;
	if ((g->count / 10) % 10 == 4)
		g->co.t4->instances->enabled = true;
	if ((g->count / 10) % 10 == 5)
		g->co.t5->instances->enabled = true;
	if ((g->count / 10) % 10 == 6)
		g->co.t6->instances->enabled = true;
	if ((g->count / 10) % 10 == 7)
		g->co.t7->instances->enabled = true;
	if ((g->count / 10) % 10 == 8)
		g->co.t8->instances->enabled = true;
	if ((g->count / 10) % 10 == 9)
		g->co.t9->instances->enabled = true;
}

void	disp_hundred(t_game *g)
{
	if ((g->count / 100) % 10 == 0)
		g->co.h0->instances->enabled = true;
	if ((g->count / 100) % 10 == 1)
		g->co.h1->instances->enabled = true;
	if ((g->count / 100) % 10 == 2)
		g->co.h2->instances->enabled = true;
	if ((g->count / 100) % 10 == 3)
		g->co.h3->instances->enabled = true;
	if ((g->count / 100) % 10 == 4)
		g->co.h4->instances->enabled = true;
	if ((g->count / 100) % 10 == 5)
		g->co.h5->instances->enabled = true;
	if ((g->count / 100) % 10 == 6)
		g->co.h6->instances->enabled = true;
	if ((g->count / 100) % 10 == 7)
		g->co.h7->instances->enabled = true;
	if ((g->count / 100) % 10 == 8)
		g->co.h8->instances->enabled = true;
	if ((g->count / 100) % 10 == 9)
		g->co.h9->instances->enabled = true;
}
