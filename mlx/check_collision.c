/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:39:31 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/12 17:42:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(t_game *g)
{
	int	tmp;

	tmp = g->p_pos_x + g->p_size_x;
	while (tmp > g->p_pos_x)
	{
		if (g->data.map_pix[g->p_pos_y - 10][g->p_pos_x] == '1')
			return (0);
		g->p_pos_x++;
	}
	return (1);
}

int	check_down(t_game *g)
{
	int	tmp;

	tmp = g->p_pos_x + g->p_size_x;
	while (tmp > g->p_pos_x)
	{
		if (g->data.map_pix[g->p_pos_y + g->p_size_y + (HEIGHT / g->data.height) + 10][g->p_pos_x] == '1')
			return (0);
		g->p_pos_x++;
	}
	return (1);
}

int	check_left(t_game *g)
{
	int	tmp;

	tmp = g->p_pos_y + g->p_size_y;
	while (tmp > g->p_pos_y)
	{
		if (g->data.map_pix[g->p_pos_y][g->p_pos_x - 10] == '1')
			return (0);
		g->p_pos_y++;
	}
	return (1);
}

int	check_rigth(t_game *g)
{
	int	tmp;

	tmp = g->p_pos_y + g->p_size_y;
	while (tmp > g->p_pos_y)
	{
		if (g->data.map_pix[g->p_pos_y][g->p_pos_x + g->p_size_x + 10] == '1')
			return (0);
		g->p_pos_y++;
	}
	return (1);
}

