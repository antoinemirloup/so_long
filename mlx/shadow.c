/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 11:36:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	shadow(t_game *g)
{
	g->sprite.shadow1 = mlx_load_png("assets/shadow1.png");
	if (!g->sprite.shadow1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.sh1 = mlx_texture_to_image(g->mlx, g->sprite.shadow1);
	mlx_image_to_window(g->mlx, g->sprite.sh1, (g->data.p_x * WIDTH / \
		(g->data.width - 1)) - (2000 - g->p_size_x / 2), \
		(g->data.p_y * HEIGHT / g->data.height) - (1000 - g->p_size_y / 2));
}
