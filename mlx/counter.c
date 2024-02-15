/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:22:12 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 17:27:38 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	resize_numbers(t_game *g)
{
	mlx_resize_image(g->co.c0, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c1, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c2, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c3, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c4, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c5, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c6, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c7, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c8, WIDTH / (30), HEIGHT / 15);
	mlx_resize_image(g->co.c9, WIDTH / (30), HEIGHT / 15);
}

void	set_numbers(t_game *g)
{
	g->co.zero = mlx_load_png("assets/0.png");
	g->co.one = mlx_load_png("assets/1.png");
	g->co.two = mlx_load_png("assets/2.png");
	g->co.three = mlx_load_png("assets/3.png");
	g->co.four = mlx_load_png("assets/4.png");
	g->co.five = mlx_load_png("assets/5.png");
	g->co.six = mlx_load_png("assets/6.png");
	g->co.seven = mlx_load_png("assets/7.png");
	g->co.eigth = mlx_load_png("assets/8.png");
	g->co.nine = mlx_load_png("assets/9.png");
	if (!g->co.zero || !g->co.one || !g->co.two || !g->co.three || !g->co.four
		|| !g->co.five || !g->co.six || !g->co.seven || !g->co.eigth
		|| !g->co.nine)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->co.c0 = mlx_texture_to_image(g->mlx, g->co.zero);
	g->co.c1 = mlx_texture_to_image(g->mlx, g->co.one);
	g->co.c2 = mlx_texture_to_image(g->mlx, g->co.two);
	g->co.c3 = mlx_texture_to_image(g->mlx, g->co.three);
	g->co.c4 = mlx_texture_to_image(g->mlx, g->co.four);
	g->co.c5 = mlx_texture_to_image(g->mlx, g->co.five);
	g->co.c6 = mlx_texture_to_image(g->mlx, g->co.six);
	g->co.c7 = mlx_texture_to_image(g->mlx, g->co.seven);
	g->co.c8 = mlx_texture_to_image(g->mlx, g->co.eigth);
	g->co.c9 = mlx_texture_to_image(g->mlx, g->co.nine);
	resize_numbers(g);
}

void	numbers(t_game *g)
{
	char	*str;
	int		size;

	str = ft_itoa(g->count);
	size = ft_strlen(str);
	set_numbers(g);
	if (size == 1)
		disp_unit(g, str[0]);
	else if (size == 2)
	{
		disp_ten(g, str[0]);
		disp_unit(g, str[1]);
	}
	else if (size == 3)
	{
		disp_hundred(g, str[0]);
		disp_ten(g, str[1]);
		disp_unit(g, str[2]);
	}
}
