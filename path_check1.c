/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:34:38 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/07 10:44:56 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_coordinates(t_solong *g)
{
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->x < (ft_strlen(g->map[g->y]) - 1))
		{
			if (g->map[g->y][g->x] == 'P')
			{
				g->p_x = g->x;
				g->p_y = g->y;
			}
			if (g->map[g->y][g->x] == 'E')
			{
				g->e_x = g->x;
				g->e_y = g->y;
			}
			g->x++;
		}
		g->y++;
	}
}

int	scan_xy(t_solong *g, char c1, char c2)
{
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->x < (ft_strlen(g->map[g->y]) - 1))
		{
			if (g->map[g->y][g->x] == c1)
			{
				if (g->map[g->y - 1][g->x] == c2 ||
					g->map[g->y + 1][g->x] == c2 ||
					g->map[g->y][g->x - 1] == c2 ||
					g->map[g->y][g->x + 1] == c2)
					return (1);
			}
			g->x++;
		}
		g->y++;
	}
	return (0);
}

void	map_doable(t_solong *g)
{
	find_coordinates(g);
	init_x(g);
	init_y(g);
	while (scan_xy(g, 'X', '0') || scan_xy(g, 'Y', '0')
		|| scan_xy(g, 'X', 'C') || scan_xy(g, 'Y', 'C'))
	{
		if (scan_xy(g, 'X', '0') || scan_xy(g, 'Y', '0')
			|| scan_xy(g, 'X', 'C') || scan_xy(g, 'Y', 'C'))
		{
			spread_x(g);
			spread_y(g);
		}
	}
	if (scan_xy(g, 'X', 'Y') == 0)
		exit((ft_printf("Error\nMap not doable!\n"), EXIT_FAILURE));
}
