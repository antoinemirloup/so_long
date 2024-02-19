/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 17:23:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_fog(t_game *g)
{
	g->sprite.fog1 = mlx_load_png("assets/fog1.png");
	if (!g->sprite.fog1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.fog2 = mlx_load_png("assets/fog2.png");
	if (!g->sprite.fog2)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.fog3 = mlx_load_png("assets/fog3.png");
	if (!g->sprite.fog3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.fog4 = mlx_load_png("assets/fog4.png");
	if (!g->sprite.fog4)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.fogg1 = mlx_texture_to_image(g->mlx, g->sprite.fog1);
	mlx_image_to_window(g->mlx, g->sprite.fogg1, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	first_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fogg);
	mlx_delete_image(g->mlx, g->sprite.fogg1);
	g->sprite.fogg1 = mlx_texture_to_image(g->mlx, g->sprite.fog1);
	g->sprite.fogg = g->sprite.fogg1;
	mlx_image_to_window(g->mlx, g->sprite.fogg, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	second_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fogg);
	g->sprite.fogg2 = mlx_texture_to_image(g->mlx, g->sprite.fog2);
	g->sprite.fogg = g->sprite.fogg2;
	mlx_image_to_window(g->mlx, g->sprite.fogg, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	third_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fogg);
	g->sprite.fogg3 = mlx_texture_to_image(g->mlx, g->sprite.fog3);
	g->sprite.fogg = g->sprite.fogg3;
	mlx_image_to_window(g->mlx, g->sprite.fogg, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	fourth_fog(t_game *g)
{
	mlx_delete_image(g->mlx, g->sprite.fogg);
	g->sprite.fogg4 = mlx_texture_to_image(g->mlx, g->sprite.fog4);
	g->sprite.fogg = g->sprite.fogg4;
	mlx_image_to_window(g->mlx, g->sprite.fogg, (g->p_pos_x - \
	(2000 - g->p_size_x / 2)), (g->p_pos_y - (1000 - g->p_size_y / 2)));
}

void	fog(t_game *g)
{
	if (g->c == g->c_tot)
		first_fog(g);
	else if (g->c == g->c_tot - 1)
		second_fog(g);
	else if (g->c == g->c_tot - 2)
		third_fog(g);
	else if (g->c == g->c_tot - 3)
		fourth_fog(g);
}
