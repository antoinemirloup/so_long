/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:56:18 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/07 11:06:35 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

size_t	count_c(t_solong *g, char c)
{
	size_t	n;

	n = 0;
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->map[g->y][g->x] != '\0')
		{
			if (g->map[g->y][g->x] == c)
				n++;
			g->x++;
		}
		g->y++;
	}
	return (n);
}
