/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 11:03:11 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int			i;
	t_game		g;

	i = 0;
	get_map(&g.data);
	check_map(&g.data);
	map_doable(&g.data);
	free_tab(g.data.map);
	get_map(&g.data);
	g.c_tot = count_c(&g.data, 'C');
	open_window(&g, &g.data);
	free_tab(g.data.map);
}
