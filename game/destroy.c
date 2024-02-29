/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:13:25 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/29 13:36:18 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_textures_1(t_game *g)
{
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
}

void	delete_textures_2(t_game *g)
{
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
}

void	delete_textures_3(t_game *g)
{
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
	if (g->sprite.win_1)
		mlx_delete_texture(g->sprite.win_1);
	if (g->sprite.win_2)
		mlx_delete_texture(g->sprite.win_2);
}

void	d_a(t_game *g)
{
	mlx_close_window(g->mlx);
	free_tab(g->data.map);
	delete_textures_1(g);
	delete_textures_2(g);
	delete_textures_3(g);
	delete_images_1(g);
	delete_images_2(g);
	delete_images_3(g);
}
