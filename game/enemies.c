/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:18 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/23 11:11:50 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coord_enemy_z(t_game *g)
{
	g->z_pos_x = g->n_pos_x;
	g->z_pos_y = g->n_pos_y;
}

void	coord_enemy_y(t_game *g)
{
	g->y_pos_x = g->n_pos_x;
	g->y_pos_y = g->n_pos_y;
}

void	place_ennemies(t_game *g)
{
	g->i = 0;
	g->data.y = -1;
	while (++g->data.y < g->data.height)
	{
		g->data.x = -1;
		while (++g->data.x < g->data.width)
		{
			if (g->data.map[g->data.y][g->data.x] == 'N')
			{
				g->n_pos_x = g->data.x * (WIDTH / (float)(g->data.width - 1));
				g->n_pos_y = g->data.y * (HEIGHT / (float)(g->data.height));
				g->data.map[g->data.y][g->data.x] = 'Z' - g->i;
				if (g->data.map[g->data.y][g->data.x] == 'Z')
					coord_enemy_z(g);
				else if (g->data.map[g->data.y][g->data.x] == 'Y')
					coord_enemy_y(g);
				g->i++;
			}
		}
	}
}

void	resize_enemies(t_game *g)
{
	if (mlx_resize_image(g->sprite.enemy1a, g->p_size_x, \
		g->p_size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy1b, g->p_size_x, \
		g->p_size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy2a, g->p_size_x, \
		g->p_size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_resize_image(g->sprite.enemy2b, g->p_size_x, \
		g->p_size_y * 0.7) == false)
		exit((ft_printf("Error\nResizing image!\n"), d_a(g), EXIT_FAILURE));
}

void	set_enemies(t_game *g)
{
	place_ennemies(g);
	g->sprite.enemya = mlx_load_png("assets/alien1.png");
	if (!g->sprite.enemya)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.enemyb = mlx_load_png("assets/alien2.png");
	if (!g->sprite.enemyb)
		exit((ft_printf("Error\nLoading image!\n"), EXIT_FAILURE));
	g->sprite.enemy1a = mlx_texture_to_image(g->mlx, g->sprite.enemya);
	g->sprite.enemy1b = mlx_texture_to_image(g->mlx, g->sprite.enemyb);
	g->sprite.enemy2a = mlx_texture_to_image(g->mlx, g->sprite.enemya);
	g->sprite.enemy2b = mlx_texture_to_image(g->mlx, g->sprite.enemyb);
	resize_enemies(g);
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1a, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy1b, g->z_pos_x, \
		g->z_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy2a, g->y_pos_x, \
		g->y_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
	if (mlx_image_to_window(g->mlx, g->sprite.enemy2b, g->y_pos_x, \
		g->y_pos_y) == -1)
		exit((ft_printf("Error\nImage on window!\n"), d_a(g), EXIT_FAILURE));
}

void	move_enemies(t_game *g)
{
	int	n1_coord_x;
	int	n1_coord_y;
	int	n2_coord_x;
	int	n2_coord_y;

	n1_coord_x = round(g->sprite.enemy1a->instances[0].x * g->data.width / WIDTH);
	n1_coord_y = round(g->sprite.enemy1a->instances[0].y * g->data.height / HEIGHT);
	n2_coord_x = round(g->sprite.enemy2a->instances[0].x * g->data.width / WIDTH);
	n2_coord_y = round(g->sprite.enemy2a->instances[0].y * g->data.height / HEIGHT);
	if (g->e == 0)
	{
		g->sprite.enemy1 = g->sprite.enemy1a;
		g->sprite.enemy2 = g->sprite.enemy2a;
	}
	if (g->dir_1 == 1)
	{
		g->e = 1;
		if (g->data.map[n1_coord_y - 1][n1_coord_x] != '0' && g->a % 2 == 0)
			g->dir_1 = 0;
		else
		{
			if (g->a % 2 == 0)
			{
				g->data.map[n1_coord_y - 1][n1_coord_x] = 'Z';
				g->data.map[n1_coord_y][n1_coord_x] = '0';
			}
			if (g->sprite.enemy1 == g->sprite.enemy1a)
			{
				g->sprite.enemy1 = g->sprite.enemy1b;
				g->sprite.enemy1a->instances->enabled = false;
				g->sprite.enemy1b->instances->enabled = true;
				g->sprite.enemy1a->instances[0].y -= g->p_size_y / 2;
				g->sprite.enemy1b->instances[0].y -= g->p_size_y / 2;
				g->a++;
			}
			else if (g->sprite.enemy1 == g->sprite.enemy1b)
			{
				g->sprite.enemy1 = g->sprite.enemy1a;
				g->sprite.enemy1a->instances->enabled = true;
				g->sprite.enemy1b->instances->enabled = false;
				g->sprite.enemy1a->instances[0].y -= g->p_size_y / 2;
				g->sprite.enemy1b->instances[0].y -= g->p_size_y / 2;
				g->a++;
			}
		}
	}
	if (g->dir_1 == 0)
	{
		g->e = 1;
		if (g->data.map[n1_coord_y + 1][n1_coord_x] != '0' && g->a % 2 == 0)
			g->dir_1 = 1;
		else
		{
			if (g->a % 2 == 0)
			{
				g->data.map[n1_coord_y + 1][n1_coord_x] = 'Z';
				g->data.map[n1_coord_y][n1_coord_x] = '0';
			}
			if (g->sprite.enemy1 == g->sprite.enemy1a)
			{
				g->sprite.enemy1 = g->sprite.enemy1b;
				g->sprite.enemy1a->instances->enabled = false;
				g->sprite.enemy1b->instances->enabled = true;
				g->sprite.enemy1a->instances[0].y += g->p_size_y / 2;
				g->sprite.enemy1b->instances[0].y += g->p_size_y / 2;
				g->a++;
			}
			else if (g->sprite.enemy1 == g->sprite.enemy1b)
			{
				g->sprite.enemy1 = g->sprite.enemy1a;
				g->sprite.enemy1a->instances->enabled = true;
				g->sprite.enemy1b->instances->enabled = false;
				g->sprite.enemy1a->instances[0].y += g->p_size_y / 2;
				g->sprite.enemy1b->instances[0].y += g->p_size_y / 2;
				g->a++;
			}
		}
	}
	if (g->dir_2 == 1)
	{
		g->e = 1;
		if (g->data.map[n2_coord_y - 1][n2_coord_x] != '0' && g->b % 2 == 0)
			g->dir_2 = 0;
		else
		{
			if (g->b % 2 == 0)
			{
				g->data.map[n2_coord_y - 1][n2_coord_x] = 'Z';
				g->data.map[n2_coord_y][n2_coord_x] = '0';
			}
			if (g->sprite.enemy2 == g->sprite.enemy2a)
			{
				g->sprite.enemy2 = g->sprite.enemy2b;
				g->sprite.enemy2a->instances->enabled = false;
				g->sprite.enemy2b->instances->enabled = true;
				g->sprite.enemy2a->instances[0].y -= g->p_size_y / 2;
				g->sprite.enemy2b->instances[0].y -= g->p_size_y / 2;
				g->b++;
			}
			else if (g->sprite.enemy2 == g->sprite.enemy2b)
			{
				g->sprite.enemy2 = g->sprite.enemy2a;
				g->sprite.enemy2a->instances->enabled = true;
				g->sprite.enemy2b->instances->enabled = false;
				g->sprite.enemy2a->instances[0].y -= g->p_size_y / 2;
				g->sprite.enemy2b->instances[0].y -= g->p_size_y / 2;
				g->b++;
			}
		}
	}
	if (g->dir_2 == 0)
	{
		g->e = 1;
		if (g->data.map[n2_coord_y + 1][n2_coord_x] != '0' && g->b % 2 == 0)
			g->dir_2 = 1;
		else
		{
			if (g->b % 2 == 0)
			{
				g->data.map[n2_coord_y + 1][n2_coord_x] = 'Z';
				g->data.map[n2_coord_y][n2_coord_x] = '0';
			}
			if (g->sprite.enemy2 == g->sprite.enemy2a)
			{
				g->sprite.enemy2 = g->sprite.enemy2b;
				g->sprite.enemy2a->instances->enabled = false;
				g->sprite.enemy2b->instances->enabled = true;
				g->sprite.enemy2a->instances[0].y += g->p_size_y / 2;
				g->sprite.enemy2b->instances[0].y += g->p_size_y / 2;
				g->b++;
			}
			else if (g->sprite.enemy2 == g->sprite.enemy2b)
			{
				g->sprite.enemy2 = g->sprite.enemy2a;
				g->sprite.enemy2a->instances->enabled = true;
				g->sprite.enemy2b->instances->enabled = false;
				g->sprite.enemy2a->instances[0].y += g->p_size_y / 2;
				g->sprite.enemy2b->instances[0].y += g->p_size_y / 2;
				g->b++;
			}
		}
	}
}
