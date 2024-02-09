/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:09 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 10:10:18 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int			i;
	t_solong	s;
	t_game		g;

	i = 0;
	get_map(&s);
	check_map(&s);
	map_doable(&s);
	free_tab(s.map);
	open_window(&g);
}
