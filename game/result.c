/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:10:10 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/22 14:17:38 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_texture_t	*result_unit(t_game *g)
{
	if (g->count % 10 == 0)
		g->co.r[0] = g->co.zero;
	if (g->count % 10 == 1)
		g->co.r[0] = g->co.one;
	if (g->count % 10 == 2)
		g->co.r[0] = g->co.two;
	if (g->count % 10 == 3)
		g->co.r[0] = g->co.three;
	if (g->count % 10 == 4)
		g->co.r[0] = g->co.four;
	if (g->count % 10 == 5)
		g->co.r[0] = g->co.five;
	if (g->count % 10 == 6)
		g->co.r[0] = g->co.six;
	if (g->count % 10 == 7)
		g->co.r[0] = g->co.seven;
	if (g->count % 10 == 8)
		g->co.r[0] = g->co.eigth;
	if (g->count % 10 == 9)
		g->co.r[0] = g->co.nine;
	return (g->co.r[0]);
}

mlx_texture_t	*result_ten(t_game *g)
{
	if ((g->count / 10) % 10 == 0)
		g->co.r[1] = g->co.zero;
	if ((g->count / 10) % 10 == 1)
		g->co.r[1] = g->co.one;
	if ((g->count / 10) % 10 == 2)
		g->co.r[1] = g->co.two;
	if ((g->count / 10) % 10 == 3)
		g->co.r[1] = g->co.three;
	if ((g->count / 10) % 10 == 4)
		g->co.r[1] = g->co.four;
	if ((g->count / 10) % 10 == 5)
		g->co.r[1] = g->co.five;
	if ((g->count / 10) % 10 == 6)
		g->co.r[1] = g->co.six;
	if ((g->count / 10) % 10 == 7)
		g->co.r[1] = g->co.seven;
	if ((g->count / 10) % 10 == 8)
		g->co.r[1] = g->co.eigth;
	if ((g->count / 10) % 10 == 9)
		g->co.r[1] = g->co.nine;
	return (g->co.r[1]);
}

mlx_texture_t	*result_hundred(t_game *g)
{
	if ((g->count / 100) % 10 == 0)
		g->co.r[2] = g->co.zero;
	if ((g->count / 100) % 10 == 1)
		g->co.r[2] = g->co.one;
	if ((g->count / 100) % 10 == 2)
		g->co.r[2] = g->co.two;
	if ((g->count / 100) % 10 == 3)
		g->co.r[2] = g->co.three;
	if ((g->count / 100) % 10 == 4)
		g->co.r[2] = g->co.four;
	if ((g->count / 100) % 10 == 5)
		g->co.r[2] = g->co.five;
	if ((g->count / 100) % 10 == 6)
		g->co.r[2] = g->co.six;
	if ((g->count / 100) % 10 == 7)
		g->co.r[2] = g->co.seven;
	if ((g->count / 100) % 10 == 8)
		g->co.r[2] = g->co.eigth;
	if ((g->count / 100) % 10 == 9)
		g->co.r[2] = g->co.nine;
	return (g->co.r[2]);
}
