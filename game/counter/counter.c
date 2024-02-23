/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:22:12 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 15:23:06 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_numbers(t_game *g)
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
		exit((ft_printf("Error\nLoading image!\n"), d_a(g), EXIT_FAILURE));
}

void	set_numbers(t_game *g)
{
	get_units(g);
	get_ten(g);
	get_hundred(g);
}

void	numbers(t_game *g)
{
	disable_units(g);
	disable_ten(g);
	disable_hundred(g);
	disp_unit(g);
	disp_ten(g);
	disp_hundred(g);
}
