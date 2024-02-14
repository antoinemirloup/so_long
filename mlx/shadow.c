/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:15:06 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/14 14:43:21 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_shadow(t_game *g)
{
	g->sprite.shadow1 = mlx_load_png("assets/shadow1.png");
	g->sprite.shadow2 = mlx_load_png("assets/shadow2.png");
	g->sprite.shadow3 = mlx_load_png("assets/shadow3.png");
	g->sprite.shadow4 = mlx_load_png("assets/shadow4.png");
	if (!g->sprite.shadow1 || !g->sprite.shadow2 || !g->sprite.shadow3 \
		|| !g->sprite.shadow4)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.sh1 = mlx_texture_to_image(g->mlx, g->sprite.shadow1);
	g->sprite.sh2 = mlx_texture_to_image(g->mlx, g->sprite.shadow2);
	g->sprite.sh3 = mlx_texture_to_image(g->mlx, g->sprite.shadow3);
	g->sprite.sh4 = mlx_texture_to_image(g->mlx, g->sprite.shadow4);
	mlx_image_to_window(g->mlx, g->sprite.sh1, (g->data.p_x * WIDTH / \
		(g->data.width - 1)) - (2000 - g->p_size_x / 2), \
		(g->data.p_y * HEIGHT / g->data.height) - (1000 - g->p_size_y / 2));
}

void	shadow(t_game *g)
{
	int	c;

	c = 1;
	set_shadow(g);
	if (g->data.map[(int) g->p_pos_y * g->data.height / HEIGHT][(int) g->p_pos_x * (g->data.width - 1)/ WIDTH] == 'C')
	{
		mlx_delete_image(g->mlx, g->sprite.sh1);
		mlx_image_to_window(g->mlx, g->sprite.sh2, (g->p_pos_x * WIDTH / \
		(g->data.width - 1)) - (2000 - g->p_size_x / 2), \
		(g->p_pos_y * HEIGHT / g->data.height) - (1000 - g->p_size_y / 2));
		c++;
	}
}
