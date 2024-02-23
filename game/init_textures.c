/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:13:26 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 16:04:52 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_textures_2(t_game *g)
{
	g->co.zero = NULL;
	g->co.one = NULL;
	g->co.two = NULL;
	g->co.three = NULL;
	g->co.four = NULL;
	g->co.five = NULL;
	g->co.six = NULL;
	g->co.seven = NULL;
	g->co.eigth = NULL;
	g->co.nine = NULL;
	g->co.r[0] = NULL;
	g->co.r[1] = NULL;
	g->co.r[2] = NULL;
	g->d.black_screen = NULL;
	g->d.death1 = NULL;
	g->d.death2 = NULL;
	g->d.death3 = NULL;
	g->d.death4 = NULL;
	g->d.death5 = NULL;
	g->d.death6 = NULL;
	g->d.death7 = NULL;
	g->d.death8 = NULL;
}

void	init_textures(t_game *g)
{
	g->sprite.dino_left = NULL;
	g->sprite.dino_right = NULL;
	g->sprite.back = NULL;
	g->sprite.bush = NULL;
	g->sprite.nest = NULL;
	g->sprite.bat1 = NULL;
	g->sprite.bat2 = NULL;
	g->sprite.bat3 = NULL;
	g->sprite.fog1 = NULL;
	g->sprite.fog2 = NULL;
	g->sprite.fog3 = NULL;
	g->sprite.fog4 = NULL;
	g->sprite.success = NULL;
	g->sprite.enemya = NULL;
	g->sprite.enemyb = NULL;
	init_textures_2(g);
}
