/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/13 13:01:13 by amirloup         ###   ########.fr       */
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
	get_map_pix(&g.data);
	fill_map_pix(&g);
	open_window(&g, &g.data);
	// while (g.data.map_pix[i])
	// {
	// 	printf("%s\n", g.data.map_pix[i]);
	// 	i++;
	// }
	free_tab(g.data.map_pix);
	free_tab(g.data.map);
}
