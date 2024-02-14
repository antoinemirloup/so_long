/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_shadow(t_game *g)
{
	g->sprite.shadow = mlx_load_png("assets/shadow.png");
	if (!g->sprite.shadow)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.sh = mlx_texture_to_image(g->mlx, g->sprite.shadow);
	mlx_image_to_window(g->mlx, g->sprite.sh, (g->data.p_x * WIDTH / \
		(g->data.width - 1)) - (2000 - g->p_size_x / 2), \
		(g->data.p_y * HEIGHT / g->data.height) - (1000 - g->p_size_y / 2));
}

void	first_shadow(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.sh);
	g->sprite.shadow = mlx_load_png("assets/shadow.png");
	g->sprite.sh = mlx_texture_to_image(g->mlx, g->sprite.shadow);
	mlx_resize_image(g->sprite.sh, 6000, 3000);
	mlx_image_to_window(g->mlx, g->sprite.sh, (g->p_pos_x - \
	(3000 - g->p_size_x / 2)), (g->p_pos_y - (1500 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c = 1;
}

void	second_shadow(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.sh);
	g->sprite.shadow = mlx_load_png("assets/shadow.png");
	g->sprite.sh = mlx_texture_to_image(g->mlx, g->sprite.shadow);
	mlx_resize_image(g->sprite.sh, 8000, 4000);
	mlx_image_to_window(g->mlx, g->sprite.sh, (g->p_pos_x - \
	(4000 - g->p_size_x / 2)), (g->p_pos_y - (2000 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c = 2;
}

void	third_shadow(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.sh);
	g->sprite.shadow = mlx_load_png("assets/shadow.png");
	g->sprite.sh = mlx_texture_to_image(g->mlx, g->sprite.shadow);
	mlx_resize_image(g->sprite.sh, 10000, 5000);
	mlx_image_to_window(g->mlx, g->sprite.sh, (g->p_pos_x - \
	(5000 - g->p_size_x / 2)), (g->p_pos_y - (2500 - g->p_size_y / 2)));
	g->data.map[g->p_coord_y][g->p_coord_x] = '0';
	g->c = 3;
}

void	shadow(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'C')
	{
		if (g->c == 0)
			first_shadow(g);
		else if (g->c == 1)
			second_shadow(g);
		else if (g->c == 2)
			third_shadow(g);
	}
}
