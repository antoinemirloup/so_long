/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 10:12:08 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_on_window(t_game *g)
{
	if (mlx_image_to_window(g->mlx, g->sprite.wall, g->w_pos_x, \
		g->w_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}

void	walls(t_game *g, t_solong *s)
{
	g->w_size_x = round(WIDTH / (float)(s->width - 1));
	g->w_size_y = round(HEIGHT / (float)(s->height));
	g->sprite.bush = mlx_load_png("assets/bush.png");
	if (!g->sprite.bush)
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
	g->sprite.wall = mlx_texture_to_image(g->mlx, g->sprite.bush);
	if (mlx_resize_image(g->sprite.wall, g->w_size_x, g->w_size_y) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
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
				wall_on_window(g);
			}
			s->x++;
		}
	}
}
