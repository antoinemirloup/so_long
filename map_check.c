/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:50:28 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/02 15:59:23 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_y(char **argv)
{
	int		fd;
	int		n;
	char	*line;

	n = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((perror("Error while opening the map!"), EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		n++;
	}
	close (fd);
	return (n);
}

char	**get_map(char **argv)
{
	int		fd;
	char	**map;
	int		i;
	int		lines;

	i = 0;
	lines = count_y(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((perror("Error while opening the map!"), EXIT_FAILURE));
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		exit((perror("Mem error!"), free_tab(map), EXIT_FAILURE));
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

int	check_walls(char **argv)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = get_map(argv);
	while (map[y] != NULL)
	{
		if (y == 0 || y == count_y(argv - 1))
		{
			while (map[y][x] != '\n' && map[y][x] != '\0')
			{
				if (map[y][x] != '1')
				{
					free_tab(map);
					exit((perror("Wall got a hole!"), EXIT_FAILURE));
				}
				x++;
			}
		}
		else
		{
			while (map[y][x] != '\n' && map[y][x] != '\0')
			{
				if (map[y][0] != '1' || map[y][ft_strlen(map[y])] != '1')
				{
					free_tab(map);
					exit((perror("Wall got a hole!"), EXIT_FAILURE));
				}
				x++;
			}
		}
		y++;
	}
	free_tab(map);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**map;

	i = 0;
	map = get_map(argv);
	if (argc > 1)
	{
		if (check_walls(argv) == 1)
		{
			while (map[i])
			{
				printf("%s", map[i]);
				i++;
			}
			free_tab(map);
		}
	}
}
