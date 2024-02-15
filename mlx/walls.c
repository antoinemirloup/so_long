/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 10:55:05 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walls(t_game *g, t_solong *s)
{
	g->w_size_x = round(WIDTH / (float)(s->width - 1));
	g->w_size_y = round(HEIGHT / (float)(s->height));
	g->sprite.bush = mlx_load_png("assets/bush.png");
	if (!g->sprite.bush)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.wall = mlx_texture_to_image(g->mlx, g->sprite.bush);
	mlx_resize_image(g->sprite.wall, g->w_size_x, g->w_size_y);
	s->y = -1;
	while (++s->y < s->height)
	{
		s->x = 0;
		while (s->x < s->width)
		{
			if (s->map[s->y][s->x] == '1')
			{
				g->w_pos_x = s->x * (WIDTH / (float)(s->width - 1));
				g->w_pos_y = s->y * (HEIGHT / (float)(s->height));
				mlx_image_to_window(g->mlx, g->sprite.wall, g->w_pos_x, \
					g->w_pos_y);
			}
			s->x++;
		}
	}
}
