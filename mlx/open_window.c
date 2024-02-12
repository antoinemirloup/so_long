/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:50:49 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/12 17:47:39 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_hook(void *param)
{
	t_game	*g;
	
	g = param;

	g->p_pos_x = g->sprite.player->instances[0].x;
	g->p_pos_y = g->sprite.player->instances[0].y;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(g->mlx);
	if (mlx_is_key_down(g->mlx, MLX_KEY_W) && check_up(g) == 1)
		g->sprite.player->instances[0].y -= 10;
	if (mlx_is_key_down(g->mlx, MLX_KEY_S) && check_down(g) == 1)
		g->sprite.player->instances[0].y += 10;
	if (mlx_is_key_down(g->mlx, MLX_KEY_A) && check_left(g) == 1)
		g->sprite.player->instances[0].x -= 10;
	if (mlx_is_key_down(g->mlx, MLX_KEY_D) && check_rigth(g) == 1)
		g->sprite.player->instances[0].x += 10;
}

void	open_window(t_game *g, t_solong *s)
{
	int	i;

	i = 0;
	g->mlx = mlx_init(WIDTH, HEIGHT, "new window", true);
	mlx_set_window_pos(g->mlx, 1000, 500);
	if (!g->mlx)
		exit((ft_printf("Error\nInitializing MLX!\n"), EXIT_FAILURE));
	// background(g);
	walls(g, s);
	player(g, s);
	// exit_game(g, s);
	mlx_loop_hook(g->mlx, ft_hook, (void *)g);
	mlx_loop(g->mlx);
	while (g->data.map_pix[i])
	{
		printf("%s\n", g->data.map_pix[i]);
		i++;
	}
	destroy_all(g);
	mlx_terminate(g->mlx);
}
