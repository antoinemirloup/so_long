/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:36:51 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/08 14:46:55 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_x(t_solong *g)
{
	if (g->map[g->p_y - 1][g->p_x] == '0' || g->map[g->p_y - 1][g->p_x] == 'C')
		g->map[g->p_y - 1][g->p_x] = 'X';
	if (g->map[g->p_y + 1][g->p_x] == '0' || g->map[g->p_y + 1][g->p_x] == 'C')
		g->map[g->p_y + 1][g->p_x] = 'X';
	if (g->map[g->p_y][g->p_x - 1] == '0' || g->map[g->p_y][g->p_x - 1] == 'C')
		g->map[g->p_y][g->p_x - 1] = 'X';
	if (g->map[g->p_y][g->p_x + 1] == '0' || g->map[g->p_y][g->p_x + 1] == 'C')
		g->map[g->p_y][g->p_x + 1] = 'X';
}

void	init_y(t_solong *g)
{
	if (g->map[g->e_y - 1][g->e_x] == '0' || g->map[g->e_y - 1][g->e_x] == 'C')
		g->map[g->e_y - 1][g->e_x] = 'Y';
	if (g->map[g->e_y + 1][g->e_x] == '0' || g->map[g->e_y + 1][g->e_x] == 'C')
		g->map[g->e_y + 1][g->e_x] = 'Y';
	if (g->map[g->e_y][g->e_x - 1] == '0' || g->map[g->e_y][g->e_x - 1] == 'C')
		g->map[g->e_y][g->e_x - 1] = 'Y';
	if (g->map[g->e_y][g->e_x + 1] == '0' || g->map[g->e_y][g->e_x + 1] == 'C')
		g->map[g->e_y][g->e_x + 1] = 'Y';
}

void	spread_x(t_solong *g)
{
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->x < (ft_strlen(g->map[g->y]) - 1))
		{
			if (g->map[g->y][g->x] == 'X')
			{
				if (g->map[g->y - 1][g->x] == '0' ||
					g->map[g->y - 1][g->x] == 'C')
					g->map[g->y - 1][g->x] = 'X';
				if (g->map[g->y + 1][g->x] == '0' ||
					g->map[g->y + 1][g->x] == 'C')
					g->map[g->y + 1][g->x] = 'X';
				if (g->map[g->y][g->x - 1] == '0' ||
					g->map[g->y][g->x - 1] == 'C')
					g->map[g->y][g->x - 1] = 'X';
				if (g->map[g->y][g->x + 1] == '0' ||
					g->map[g->y][g->x + 1] == 'C')
					g->map[g->y][g->x + 1] = 'X';
			}
			g->x++;
		}
		g->y++;
	}
}

void	spread_y(t_solong *g)
{
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->x < (ft_strlen(g->map[g->y]) - 1))
		{
			if (g->map[g->y][g->x] == 'Y')
			{
				if (g->map[g->y - 1][g->x] == '0' ||
					g->map[g->y - 1][g->x] == 'C')
					g->map[g->y - 1][g->x] = 'Y';
				if (g->map[g->y + 1][g->x] == '0' ||
					g->map[g->y + 1][g->x] == 'C')
					g->map[g->y + 1][g->x] = 'Y';
				if (g->map[g->y][g->x - 1] == '0' ||
					g->map[g->y][g->x - 1] == 'C')
					g->map[g->y][g->x - 1] = 'Y';
				if (g->map[g->y][g->x + 1] == '0' ||
					g->map[g->y][g->x + 1] == 'C')
					g->map[g->y][g->x + 1] = 'Y';
			}
			g->x++;
		}
		g->y++;
	}
}
