/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:39:37 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/12 14:38:01 by amirloup         ###   ########.fr       */
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

void	fill_map_pix(t_solong *data)
{
	data->y = -1;
	while (++data->y < data->height)
	{
		data->x = -1;
		while (++data->x < data->width - 1)
		{
			if (data->map[data->y][data->x] == '1')
			{
				data->wall_x = data->x * (WIDTH / (data->width - 1));
				data->wall_y = data->y * (HEIGHT / data->height);
				data->i = data->wall_y;
				while (data->i < data->wall_y + (HEIGHT / data->height))
				{
					data->j = data->wall_x;
					while (data->j < data->wall_x + (WIDTH / data-> width))
					{
						data->map_pix[data->i][data->j] = '1';
						data->j++;
					}
					data->i++;
				}
			}
		}
	}
}
