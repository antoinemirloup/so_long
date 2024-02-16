/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:23:56 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 12:46:00 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	disp_unit(t_game *g)
{
	g->co.tab[1] = g->co.c0;
	g->co.tab[2] = g->co.c0;
	if (g->count % 10 == 0)
		g->co.tab[0] = g->co.c0;
	if (g->count % 10 == 1)
		g->co.tab[0] = g->co.c1;
	if (g->count % 10 == 2)
		g->co.tab[0] = g->co.c2;
	if (g->count % 10 == 3)
		g->co.tab[0] = g->co.c3;
	if (g->count % 10 == 4)
		g->co.tab[0] = g->co.c4;
	if (g->count % 10 == 5)
		g->co.tab[0] = g->co.c5;
	if (g->count % 10 == 6)
		g->co.tab[0] = g->co.c6;
	if (g->count % 10 == 7)
		g->co.tab[0] = g->co.c7;
	if (g->count % 10 == 8)
		g->co.tab[0] = g->co.c8;
	if (g->count % 10 == 9)
		g->co.tab[0] = g->co.c9;
}

void	disp_ten(t_game *g)
{
	g->co.tab[2] = g->co.c0;
	if ((g->count / 10) % 10 == 0)
		g->co.tab[1] = g->co.c0;
	if ((g->count / 10) % 10 == 1)
		g->co.tab[1] = g->co.c1;
	if ((g->count / 10) % 10 == 2)
		g->co.tab[1] = g->co.c2;
	if ((g->count / 10) % 10 == 3)
		g->co.tab[1] = g->co.c3;
	if ((g->count / 10) % 10 == 4)
		g->co.tab[1] = g->co.c4;
	if ((g->count / 10) % 10 == 5)
		g->co.tab[1] = g->co.c5;
	if ((g->count / 10) % 10 == 6)
		g->co.tab[1] = g->co.c6;
	if ((g->count / 10) % 10 == 7)
		g->co.tab[1] = g->co.c7;
	if ((g->count / 10) % 10 == 8)
		g->co.tab[1] = g->co.c8;
	if ((g->count / 10) % 10 == 9)
		g->co.tab[1] = g->co.c9;
}

void	disp_hundred(t_game *g)
{
	if ((g->count / 100) % 10 == 0)
		g->co.tab[2] = g->co.c0;
	if ((g->count / 100) % 10 == 1)
		g->co.tab[2] = g->co.c1;
	if ((g->count / 100) % 10 == 2)
		g->co.tab[2] = g->co.c2;
	if ((g->count / 100) % 10 == 3)
		g->co.tab[2] = g->co.c3;
	if ((g->count / 100) % 10 == 4)
		g->co.tab[2] = g->co.c4;
	if ((g->count / 100) % 10 == 5)
		g->co.tab[2] = g->co.c5;
	if ((g->count / 100) % 10 == 6)
		g->co.tab[2] = g->co.c6;
	if ((g->count / 100) % 10 == 7)
		g->co.tab[2] = g->co.c7;
	if ((g->count / 100) % 10 == 8)
		g->co.tab[2] = g->co.c8;
	if ((g->count / 100) % 10 == 9)
		g->co.tab[2] = g->co.c9;
}
