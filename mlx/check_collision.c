/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:31 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 17:28:30 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(t_game *g)
{
	if (g->data.map[g->p_coord_y - 1][g->p_coord_x] == '1')
		return (0);
	return (1);
}

int	check_down(t_game *g)
{
	if (g->data.map[g->p_coord_y + 1][g->p_coord_x] == '1')
		return (0);
	return (1);
}

int	check_left(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x - 1] == '1')
		return (0);
	return (1);
}

int	check_rigth(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x + 1] == '1')
		return (0);
	return (1);
}
