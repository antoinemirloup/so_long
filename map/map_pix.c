/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:39:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/13 12:35:47 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_map_pix(t_solong *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	data->map_pix = malloc(sizeof (char *) * (HEIGHT + 1));
	if (!data->map_pix)
		exit((ft_printf("Error\nMem error!\n"), \
		free_tab(data->map_pix), EXIT_FAILURE));
	while (i < HEIGHT)
	{
		j = 0;
		data->map_pix[i] = malloc (sizeof (char) * (WIDTH + 1));
		if (!data->map_pix[i])
			exit((ft_printf("Error\nMem error!\n"), \
			free_tab(data->map), EXIT_FAILURE));
		while (j < WIDTH)
		{
			data->map_pix[i][j] = '0';
			j++;
		}
		data->map_pix[i][j] = '\0';
		i++;
	}
	data->map_pix[i] = NULL;
}

void	fill_map_pix(t_game *g)
{
	int	i;
	int	j;

	i = g->w_pos_y;
	while (i < g->w_pos_y + g->w_size_y && g->data.map_pix[i])
	{
		j = g->w_pos_x;
		while (j < g->w_pos_x + g->w_size_x && g->data.map_pix[i][j])
		{
			g->data.map_pix[i][j] = '1';
			j++;
		}
		i++;
	}
}
