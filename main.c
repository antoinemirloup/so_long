/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/07 10:53:25 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int			i;
	t_solong	g;

	i = 0;
	get_map(argv, &g);
	check_map(&g);
	map_doable(&g);
	if (argc > 1)
	{
		while (g.map[i])
		{
			printf("%s", g.map[i]);
			i++;
		}
		free_tab(g.map);
	}
}
