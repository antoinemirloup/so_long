/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:08:11 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 13:15:23 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_texture_t	*result_unit(t_game *g)
{
	if (g->count % 10 == 0)
		g->co.r[0] = g->co.zero;
	if (g->count % 10 == 1)
		g->co.r[0] = g->co.one;
	if (g->count % 10 == 2)
		g->co.r[0] = g->co.two;
	if (g->count % 10 == 3)
		g->co.r[0] = g->co.three;
	if (g->count % 10 == 4)
		g->co.r[0] = g->co.four;
	if (g->count % 10 == 5)
		g->co.r[0] = g->co.five;
	if (g->count % 10 == 6)
		g->co.r[0] = g->co.six;
	if (g->count % 10 == 7)
		g->co.r[0] = g->co.seven;
	if (g->count % 10 == 8)
		g->co.r[0] = g->co.eigth;
	if (g->count % 10 == 9)
		g->co.r[0] = g->co.nine;
	return (g->co.r[0]);
}

mlx_texture_t	*result_ten(t_game *g)
{
	if ((g->count / 10) % 10 == 0)
		g->co.r[1] = g->co.zero;
	if ((g->count / 10) % 10 == 1)
		g->co.r[1] = g->co.one;
	if ((g->count / 10) % 10 == 2)
		g->co.r[1] = g->co.two;
	if ((g->count / 10) % 10 == 3)
		g->co.r[1] = g->co.three;
	if ((g->count / 10) % 10 == 4)
		g->co.r[1] = g->co.four;
	if ((g->count / 10) % 10 == 5)
		g->co.r[1] = g->co.five;
	if ((g->count / 10) % 10 == 6)
		g->co.r[1] = g->co.six;
	if ((g->count / 10) % 10 == 7)
		g->co.r[1] = g->co.seven;
	if ((g->count / 10) % 10 == 8)
		g->co.r[1] = g->co.eigth;
	if ((g->count / 10) % 10 == 9)
		g->co.r[1] = g->co.nine;
	return (g->co.r[1]);
}

mlx_texture_t	*result_hundred(t_game *g)
{
	if ((g->count / 100) % 10 == 0)
		g->co.r[2] = g->co.zero;
	if ((g->count / 100) % 10 == 1)
		g->co.r[2] = g->co.one;
	if ((g->count / 100) % 10 == 2)
		g->co.r[2] = g->co.two;
	if ((g->count / 100) % 10 == 3)
		g->co.r[2] = g->co.three;
	if ((g->count / 100) % 10 == 4)
		g->co.r[2] = g->co.four;
	if ((g->count / 100) % 10 == 5)
		g->co.r[2] = g->co.five;
	if ((g->count / 100) % 10 == 6)
		g->co.r[2] = g->co.six;
	if ((g->count / 100) % 10 == 7)
		g->co.r[2] = g->co.seven;
	if ((g->count / 100) % 10 == 8)
		g->co.r[2] = g->co.eigth;
	if ((g->count / 100) % 10 == 9)
		g->co.r[2] = g->co.nine;
	return (g->co.r[2]);
}

void	exit_game(t_game *g)
{
	if (g->data.map[g->p_coord_y][g->p_coord_x] == 'F')
	{
		g->success = 1;
		mlx_image_to_window(g->mlx, g->sprite.succes, WIDTH / 2 - 375, HEIGHT \
			/ 2 - 200);
		mlx_delete_image(g->mlx, g->sprite.fo);
		g->co.result[0] = mlx_texture_to_image(g->mlx, result_unit(g));
		g->co.result[1] = mlx_texture_to_image(g->mlx, result_ten(g));
		g->co.result[2] = mlx_texture_to_image(g->mlx, result_hundred(g));
		mlx_resize_image(g->co.result[0], 200, 200);
		mlx_resize_image(g->co.result[1], 200, 200);
		mlx_resize_image(g->co.result[2], 200, 200);
		mlx_image_to_window(g->mlx, g->co.result[0], WIDTH / 2 + 100, HEIGHT \
			/ 2 + 100);
		mlx_image_to_window(g->mlx, g->co.result[1], WIDTH / 2 - 100, HEIGHT \
			/ 2 + 100);
		mlx_image_to_window(g->mlx, g->co.result[2], WIDTH / 2 - 300, HEIGHT \
			/ 2 + 100);
	}
}

void	set_exit(t_game *g)
{
	g->sprite.nest = mlx_load_png("assets/nest.png");
	if (!g->sprite.nest)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.exit_nest = mlx_texture_to_image(g->mlx, g->sprite.nest);
	mlx_resize_image(g->sprite.exit_nest, g->w_size_x, g->w_size_y / 1.2);
	g->sprite.success = mlx_load_png("assets/success.png");
	if (!g->sprite.success)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.succes = mlx_texture_to_image(g->mlx, g->sprite.success);
	mlx_resize_image(g->sprite.succes, 750, 170);
	mlx_image_to_window(g->mlx, g->sprite.exit_nest, (g->data.e_x * WIDTH / \
		g->data.width), (g->data.e_y * HEIGHT / g->data.height));
}
