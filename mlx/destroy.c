/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:25 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 17:17:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_all(t_game *g)
{
	if (g->sprite.dino)
		mlx_delete_texture(g->sprite.dino);
	if (g->sprite.back)
		mlx_delete_texture(g->sprite.back);
	if (g->sprite.bush)
		mlx_delete_texture(g->sprite.bush);
	if (g->sprite.nest)
		mlx_delete_texture(g->sprite.nest);
	if (g->sprite.player)
		mlx_delete_image(g->mlx, g->sprite.player);
	if (g->sprite.player)
		mlx_delete_image(g->mlx, g->sprite.wall);
	if (g->sprite.wall)
		mlx_delete_image(g->mlx, g->sprite.exit_nest);
	if (g->sprite.exit_nest)
		mlx_delete_image(g->mlx, g->sprite.background);
	mlx_close_window(g->mlx);
}
