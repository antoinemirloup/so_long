/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:10:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 15:50:00 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	refresh(t_game *g)
{
	g->frame++;
	if (g->frame % 4 == 0)
		battq(g);
}

void	battq(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.batt1q);
	mlx_delete_image(g->mlx, g->sprite.batt2q);
	mlx_delete_image(g->mlx, g->sprite.batt3q);
	if (g->frame %  == 0)
		mlx_image_to_window(g->mlx, g->sprite.batt1q, g->q_pos_x, g->q_pos_y);
}
