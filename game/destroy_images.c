/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:47:08 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 16:49:27 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_images_1(t_game *g)
{
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
}

void	delete_images_2(t_game *g)
{
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
}

void	delete_images_3(t_game *g)
{
	mlx_delete_image(g->mlx, g->co.h5);
	mlx_delete_image(g->mlx, g->co.h6);
	mlx_delete_image(g->mlx, g->co.h7);
	mlx_delete_image(g->mlx, g->co.h8);
	mlx_delete_image(g->mlx, g->co.h9);
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
