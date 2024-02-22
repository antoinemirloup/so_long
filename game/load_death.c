/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:50:57 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/22 16:02:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_black_screen(t_game *g)
{
	g->d.black_screen = mlx_load_png("assets/black_screen.png");
	if (!g->d.black_screen)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
}

void	load_death(t_game *g)
{
	load_black_screen(g);
	g->d.death1 = mlx_load_png("assets/death1.png");
	if (!g->d.death1)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death2 = mlx_load_png("assets/death2.png");
	if (!g->d.death2)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death3 = mlx_load_png("assets/death3.png");
	if (!g->d.death3)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death4 = mlx_load_png("assets/death4.png");
	if (!g->d.death4)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death5 = mlx_load_png("assets/death5.png");
	if (!g->d.death5)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death6 = mlx_load_png("assets/death6.png");
	if (!g->d.death6)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death7 = mlx_load_png("assets/death7.png");
	if (!g->d.death7)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->d.death8 = mlx_load_png("assets/death8.png");
	if (!g->d.death8)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
}
