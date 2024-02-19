/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/19 10:46:34 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game		g;

	get_map(&g.data);
	check_map(&g.data);
	map_doable(&g.data);
	free_tab(g.data.map);
	get_map(&g.data);
	g.c_tot = count_c(&g.data, 'C');
	g.count = 0;
	g.success = 0;
	g.q = 0;
	g.r = 0;
	g.s = 0;
	g.b_q = 1;
	g.b_r = 1;
	g.b_s = 1;
	open_window(&g, &g.data);
	free_tab(g.data.map);
}
