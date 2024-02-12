/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:31:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/12 17:37:28 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walls(t_game *g, t_solong *s)
{
	int	pos_x;
	int	pos_y;

	g->sprite.bush = mlx_load_png("assets/blue_square.png");
	if (!g->sprite.bush)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.wall = mlx_texture_to_image(g->mlx, g->sprite.bush);
	mlx_resize_image(g->sprite.wall, WIDTH / s->width, HEIGHT / s->height);
	s->y = 0;
	while (s->y < s->height)
	{
		s->x = 0;
		while (s->x < s->width - 1)
		{
			if (s->map[s->y][s->x] == '1')
			{
				pos_x = s->x * (WIDTH / (s->width - 1));
				pos_y = s->y * (HEIGHT / s->height);
				mlx_image_to_window(g->mlx, g->sprite.wall, pos_x, pos_y);
			}
			s->x++;
		}
		s->y++;
	}
}
