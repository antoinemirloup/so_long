/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:25 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 16:03:31 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	d_a(t_game *g)
{
	mlx_close_window(g->mlx);
	if (g->sprite.dino_left)
		mlx_delete_texture(g->sprite.dino_left);
	if (g->sprite.dino_right)
		mlx_delete_texture(g->sprite.dino_right);
	if (g->sprite.back)
		mlx_delete_texture(g->sprite.back);
	if (g->sprite.bush)
		mlx_delete_texture(g->sprite.bush);
	if (g->sprite.nest)
		mlx_delete_texture(g->sprite.nest);
	if (g->sprite.bat1)
		mlx_delete_texture(g->sprite.bat1);
	if (g->sprite.bat2)
		mlx_delete_texture(g->sprite.bat2);
	if (g->sprite.bat3)
		mlx_delete_texture(g->sprite.bat3);
	if (g->sprite.fog1)
		mlx_delete_texture(g->sprite.fog1);
	if (g->sprite.fog2)
		mlx_delete_texture(g->sprite.fog2);
	if (g->sprite.fog3)
		mlx_delete_texture(g->sprite.fog3);
	if (g->sprite.fog4)
		mlx_delete_texture(g->sprite.fog4);
	if (g->sprite.success)
		mlx_delete_texture(g->sprite.success);
	if (g->sprite.enemya)
		mlx_delete_texture(g->sprite.enemya);
	if (g->sprite.enemyb)
		mlx_delete_texture(g->sprite.enemyb);
	if (g->co.zero)
		mlx_delete_texture(g->co.zero);
	if (g->co.one)
		mlx_delete_texture(g->co.one);
	if (g->co.two)
		mlx_delete_texture(g->co.two);
	if (g->co.three)
		mlx_delete_texture(g->co.three);
	if (g->co.four)
		mlx_delete_texture(g->co.four);
	if (g->co.five)
		mlx_delete_texture(g->co.five);
	if (g->co.six)
		mlx_delete_texture(g->co.six);
	if (g->co.seven)
		mlx_delete_texture(g->co.seven);
	if (g->co.eigth)
		mlx_delete_texture(g->co.eigth);
	if (g->co.nine)
		mlx_delete_texture(g->co.nine);
	if (g->d.black_screen)
		mlx_delete_texture(g->d.black_screen);
	if (g->d.death1)
		mlx_delete_texture(g->d.death1);
	if (g->d.death2)
		mlx_delete_texture(g->d.death2);
	if (g->d.death3)
		mlx_delete_texture(g->d.death3);
	if (g->d.death4)
		mlx_delete_texture(g->d.death4);
	if (g->d.death5)
		mlx_delete_texture(g->d.death5);
	if (g->d.death6)
		mlx_delete_texture(g->d.death6);
	if (g->d.death7)
		mlx_delete_texture(g->d.death7);
	if (g->d.death8)
		mlx_delete_texture(g->d.death8);
	mlx_delete_image(g->mlx, g->sprite.player_left);
	mlx_delete_image(g->mlx, g->sprite.player_right);
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
	mlx_delete_image(g->mlx, g->sprite.succes);
	mlx_delete_image(g->mlx, g->sprite.enemy1a);
	mlx_delete_image(g->mlx, g->sprite.enemy1b);
	mlx_delete_image(g->mlx, g->sprite.enemy2a);
	mlx_delete_image(g->mlx, g->sprite.enemy2b);
	mlx_delete_image(g->mlx, g->sprite.enemy1);
	mlx_delete_image(g->mlx, g->sprite.enemy2);
	mlx_delete_image(g->mlx, g->co.u0);
	mlx_delete_image(g->mlx, g->co.u1);
	mlx_delete_image(g->mlx, g->co.u2);
	mlx_delete_image(g->mlx, g->co.u3);
	mlx_delete_image(g->mlx, g->co.u4);
	mlx_delete_image(g->mlx, g->co.u5);
	mlx_delete_image(g->mlx, g->co.u6);
	mlx_delete_image(g->mlx, g->co.u7);
	mlx_delete_image(g->mlx, g->co.u8);
	mlx_delete_image(g->mlx, g->co.u9);
	mlx_delete_image(g->mlx, g->co.t0);
	mlx_delete_image(g->mlx, g->co.t1);
	mlx_delete_image(g->mlx, g->co.t2);
	mlx_delete_image(g->mlx, g->co.t3);
	mlx_delete_image(g->mlx, g->co.t4);
	mlx_delete_image(g->mlx, g->co.t5);
	mlx_delete_image(g->mlx, g->co.t6);
	mlx_delete_image(g->mlx, g->co.t7);
	mlx_delete_image(g->mlx, g->co.t8);
	mlx_delete_image(g->mlx, g->co.t9);
	mlx_delete_image(g->mlx, g->co.h0);
	mlx_delete_image(g->mlx, g->co.h1);
	mlx_delete_image(g->mlx, g->co.h2);
	mlx_delete_image(g->mlx, g->co.h3);
	mlx_delete_image(g->mlx, g->co.h4);
	mlx_delete_image(g->mlx, g->co.h5);
	mlx_delete_image(g->mlx, g->co.h6);
	mlx_delete_image(g->mlx, g->co.h7);
	mlx_delete_image(g->mlx, g->co.h8);
	mlx_delete_image(g->mlx, g->co.h9);
	mlx_delete_image(g->mlx, g->co.tab[0]);
	mlx_delete_image(g->mlx, g->co.tab[1]);
	mlx_delete_image(g->mlx, g->co.tab[2]);
	mlx_delete_image(g->mlx, g->co.result[0]);
	mlx_delete_image(g->mlx, g->co.result[1]);
	mlx_delete_image(g->mlx, g->co.result[2]);
	mlx_delete_image(g->mlx, g->d.d[0]);
	mlx_delete_image(g->mlx, g->d.d[1]);
	mlx_delete_image(g->mlx, g->d.d[2]);
	mlx_delete_image(g->mlx, g->d.d[3]);
	mlx_delete_image(g->mlx, g->d.d[4]);
	mlx_delete_image(g->mlx, g->d.d[5]);
	mlx_delete_image(g->mlx, g->d.d[6]);
	mlx_delete_image(g->mlx, g->d.d[7]);
}
