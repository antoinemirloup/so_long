/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/27 11:53:46 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *g)
{
	g->c_tot = count_c(&g->data, 'C');
	g->count = 0;
	g->success = 0;
	g->q = 0;
	g->r = 0;
	g->s = 0;
	g->b_q = 1;
	g->b_r = 1;
	g->b_s = 1;
	g->time = 0;
	g->frame = 0;
	g->dir_1 = 1;
	g->dir_2 = 1;
	g->e = 0;
	g->a = 0;
	g->b = 0;
	g->alive = 1;
	g->d.i = 0;
	g->left = 0;
	g->rigth = 0;
	g->win = 0;
	g->size_x = round(WIDTH / (float)(g->data.width - 1));
	g->size_y = round(HEIGHT / (float)(g->data.height));
}

int	main(int argc, char **argv)
{
	t_game		g;

	if (argc == 2)
	{
		get_map(&g.data, argv);
		check_map(&g.data);
		map_doable(&g.data);
		free_tab(g.data.map);
		get_map(&g.data, argv);
		init(&g);
		open_window(&g, &g.data);
		free_tab(g.data.map);
	}
}
