/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:50:28 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/16 14:32:58 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_y(t_solong *data)
{
	int			fd;
	char		*line;

	data->height = 0;
	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nError while opening the map!\n"), EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		data->height++;
	}
	close (fd);
}

void	get_map(t_solong *data)
{
	int		fd;
	size_t	i;

	i = 0;
	count_y(data);
	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nError while opening the map!\n"), EXIT_FAILURE));
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		exit((ft_printf("Error\nMem error!\n"), \
		free_tab(data->map), EXIT_FAILURE));
	while (i < data->height)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			exit((ft_printf("Error\nMem error!\n"), \
			free_tab(data->map), EXIT_FAILURE));
		i++;
	}
	data->map[i] = NULL;
	if (data->map[0] != NULL)
		data->width = ft_strlen(data->map[0]);
	close (fd);
}

void	check_walls(t_solong *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < (ft_strlen(data->map[data->y]) - 1))
		{
			if (data->y == 0 || data->y == (data->height - 1))
			{
				if (data->map[data->y][data->x] != '1')
					exit((ft_printf("Error\nWall got a hole!\n"), \
					free_tab(data->map), EXIT_FAILURE));
			}
			else
			{
				if (data->map[data->y][0] != '1'
					|| data->map[data->y][ft_strlen(data->map[data->y]) - 2] \
					!= '1')
					exit((ft_printf("Error\nWall got a hole!\n"), \
					free_tab(data->map), EXIT_FAILURE));
			}
			data->x++;
		}
		data->y++;
	}
}

void	check_shape(t_solong *data)
{
	if (data->map[0] == NULL)
		exit((ft_printf("Error\nMap is empty!\n"), \
			free_tab(data->map), EXIT_FAILURE));
	data->y = 0;
	while (data->y < (data->height - 1))
	{
		if (ft_strlen(data->map[data->y]) != ft_strlen(data->map[data->y + 1]))
			exit((ft_printf("Error\nMap is not rectangular!\n"), \
			free_tab(data->map), EXIT_FAILURE));
		data->y++;
	}
}

void	check_map(t_solong *data)
{
	check_shape(data);
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->map[data->y][data->x] != '\0')
		{
			if (data->map[data->y][data->x] != '1'
				&& data->map[data->y][data->x] != '0'
				&& data->map[data->y][data->x] != 'P'
				&& data->map[data->y][data->x] != 'C'
				&& data->map[data->y][data->x] != 'E'
				&& data->map[data->y][data->x] != '\n')
				exit((ft_printf("Error\nWrong input!\n"), \
				free_tab(data->map), EXIT_FAILURE));
			data->x++;
		}
		data->y++;
	}
	if (count_c(data, 'P') != 1 || count_c(data, 'E') != 1
		|| count_c(data, 'C') < 1)
		exit((ft_printf("Error\nWrong input!\n"), \
		free_tab(data->map), EXIT_FAILURE));
	check_walls(data);
}
