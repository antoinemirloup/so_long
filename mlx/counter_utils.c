/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:23:56 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 11:29:00 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	disp_unit(t_game *g, int b)
{
	mlx_image_t	*temp;

	g->co.tab[1] = g->co.c0;
	g->co.tab[2] = g->co.c0;
	if (g->count % 10 == 0)
		temp = g->co.c0;
	if (g->count % 10 == 1)
		temp = g->co.c1;
	if (g->count % 10 == 2)
		temp = g->co.c2;
	if (g->count % 10 == 3)
		temp = g->co.c3;
	if (g->count % 10 == 4)
		temp = g->co.c4;
	if (g->count % 10 == 5)
		temp = g->co.c5;
	if (g->count % 10 == 6)
		temp = g->co.c6;
	if (g->count % 10 == 7)
		temp = g->co.c7;
	if (g->count % 10 == 8)
		temp = g->co.c8;
	if (g->count % 10 == 9)
		temp = g->co.c9;
	if (b == 0)
		g->co.tab[0] = temp;
	else if (b == 1)
		g->co.result[0] = temp;
}

void	disp_ten(t_game *g, int b)
{
	mlx_image_t	*temp;

	g->co.tab[2] = g->co.c0;
	if ((g->count / 10) % 10 == 0)
		temp = g->co.c0;
	if ((g->count / 10) % 10 == 1)
		temp = g->co.c1;
	if ((g->count / 10) % 10 == 2)
		temp = g->co.c2;
	if ((g->count / 10) % 10 == 3)
		temp = g->co.c3;
	if ((g->count / 10) % 10 == 4)
		temp = g->co.c4;
	if ((g->count / 10) % 10 == 5)
		temp = g->co.c5;
	if ((g->count / 10) % 10 == 6)
		temp = g->co.c6;
	if ((g->count / 10) % 10 == 7)
		temp = g->co.c7;
	if ((g->count / 10) % 10 == 8)
		temp = g->co.c8;
	if ((g->count / 10) % 10 == 9)
		temp = g->co.c9;
	if (b == 0)
		g->co.tab[1] = temp;
	else if (b == 1)
		g->co.result[1] = temp;
}

void	disp_hundred(t_game *g, int b)
{
	mlx_image_t	*temp;

	if ((g->count / 100) % 10 == 0)
		temp = g->co.c0;
	if ((g->count / 100) % 10 == 1)
		temp = g->co.c1;
	if ((g->count / 100) % 10 == 2)
		temp = g->co.c2;
	if ((g->count / 100) % 10 == 3)
		temp = g->co.c3;
	if ((g->count / 100) % 10 == 4)
		temp = g->co.c4;
	if ((g->count / 100) % 10 == 5)
		temp = g->co.c5;
	if ((g->count / 100) % 10 == 6)
		temp = g->co.c6;
	if ((g->count / 100) % 10 == 7)
		temp = g->co.c7;
	if ((g->count / 100) % 10 == 8)
		temp = g->co.c8;
	if ((g->count / 100) % 10 == 9)
		temp = g->co.c9;
	if (b == 0)
		g->co.tab[2] = temp;
	else if (b == 1)
		g->co.result[2] = temp;
}
