/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:25 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 12:52:29 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_all(t_game *g)
{
	if (g->sprite.icon)
		mlx_delete_texture(g->sprite.icon);
	if (g->sprite.back)
		mlx_delete_texture(g->sprite.back);
	if (g->sprite.player)
		mlx_delete_image(g->mlx, g->sprite.player);
	if (g->sprite.background)
		mlx_delete_image(g->mlx, g->sprite.background);
	mlx_close_window(g->mlx);
}
