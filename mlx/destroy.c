/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:25 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/20 14:07:08 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_all(t_game *g)
{
	mlx_close_window(g->mlx);
	mlx_delete_texture(g->sprite.dino);
	mlx_delete_texture(g->sprite.back);
	mlx_delete_texture(g->sprite.bush);
	mlx_delete_texture(g->sprite.nest);
	mlx_delete_texture(g->sprite.bat1);
	mlx_delete_texture(g->sprite.bat2);
	mlx_delete_texture(g->sprite.bat3);
	mlx_delete_texture(g->sprite.fog1);
	mlx_delete_texture(g->sprite.fog2);
	mlx_delete_texture(g->sprite.fog3);
	mlx_delete_texture(g->sprite.fog4);
	mlx_delete_texture(g->co.zero);
	mlx_delete_texture(g->co.one);
	mlx_delete_texture(g->co.two);
	mlx_delete_texture(g->co.three);
	mlx_delete_texture(g->co.four);
	mlx_delete_texture(g->co.five);
	mlx_delete_texture(g->co.six);
	mlx_delete_texture(g->co.seven);
	mlx_delete_texture(g->co.eigth);
	mlx_delete_texture(g->co.nine);
	mlx_delete_texture(g->sprite.success);
	mlx_delete_texture(g->sprite.enemya);
	mlx_delete_texture(g->sprite.enemyb);
	mlx_delete_image(g->mlx, g->sprite.player);
	mlx_delete_image(g->mlx, g->sprite.background);
	mlx_delete_image(g->mlx, g->sprite.wall);
	mlx_delete_image(g->mlx, g->sprite.exit_nest);
	mlx_delete_image(g->mlx, g->sprite.batt1q);
	mlx_delete_image(g->mlx, g->sprite.batt1r);
	mlx_delete_image(g->mlx, g->sprite.batt1s);
	mlx_delete_image(g->mlx, g->sprite.batt2q);
	mlx_delete_image(g->mlx, g->sprite.batt2r);
	mlx_delete_image(g->mlx, g->sprite.batt2s);
	mlx_delete_image(g->mlx, g->sprite.batt3q);
	mlx_delete_image(g->mlx, g->sprite.batt3r);
	mlx_delete_image(g->mlx, g->sprite.batt3s);
	mlx_delete_image(g->mlx, g->sprite.fogg1);
	mlx_delete_image(g->mlx, g->sprite.fogg2);
	mlx_delete_image(g->mlx, g->sprite.fogg3);
	mlx_delete_image(g->mlx, g->sprite.fogg4);
	mlx_delete_image(g->mlx, g->co.c0);
	mlx_delete_image(g->mlx, g->co.c1);
	mlx_delete_image(g->mlx, g->co.c2);
	mlx_delete_image(g->mlx, g->co.c3);
	mlx_delete_image(g->mlx, g->co.c4);
	mlx_delete_image(g->mlx, g->co.c5);
	mlx_delete_image(g->mlx, g->co.c6);
	mlx_delete_image(g->mlx, g->co.c7);
	mlx_delete_image(g->mlx, g->co.c8);
	mlx_delete_image(g->mlx, g->co.c9);
	mlx_delete_image(g->mlx, g->sprite.succes);
	mlx_delete_image(g->mlx, g->co.tab[0]);
	mlx_delete_image(g->mlx, g->co.tab[1]);
	mlx_delete_image(g->mlx, g->co.tab[2]);
	mlx_delete_image(g->mlx, g->sprite.battq);
	mlx_delete_image(g->mlx, g->sprite.battr);
	mlx_delete_image(g->mlx, g->sprite.batts);
	mlx_delete_image(g->mlx, g->sprite.enemy1a);
	mlx_delete_image(g->mlx, g->sprite.enemy1b);
	mlx_delete_image(g->mlx, g->sprite.enemy2a);
	mlx_delete_image(g->mlx, g->sprite.enemy2b);
	mlx_delete_image(g->mlx, g->sprite.enemy1);
	mlx_delete_image(g->mlx, g->sprite.enemy2);
}
