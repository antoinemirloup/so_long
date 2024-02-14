/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:31 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 12:03:58 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(t_game *g)
{
	int	x;
	int	y;

	x = g->p_pos_x * g->data.width / WIDTH;
	y = g->p_pos_y * g->data.height / HEIGHT;
	if (g->data.map[y - 1][x] == '1')
		return (0);
	return (1);
}

int	check_down(t_game *g)
{
	int	x;
	int	y;

	x = g->p_pos_x * g->data.width / WIDTH;
	y = g->p_pos_y * g->data.height / HEIGHT;
	if (g->data.map[y + 1][x] == '1')
		return (0);
	return (1);
}

int	check_left(t_game *g)
{
	int	x;
	int	y;

	x = g->p_pos_x * g->data.width / WIDTH;
	y = g->p_pos_y * g->data.height / HEIGHT;
	if (g->data.map[y][x - 1] == '1')
		return (0);
	return (1);
}

int	check_rigth(t_game *g)
{
	int	x;
	int	y;

	x = g->p_pos_x * g->data.width / WIDTH;
	y = g->p_pos_y * g->data.height / HEIGHT;
	if (g->data.map[y][x + 1] == '1')
		return (0);
	return (1);
}

