/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:50:28 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/07 10:48:02 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_y(char **argv, t_solong *g)
{
	int			fd;
	char		*line;

	g->lines = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nError while opening the map!\n"), EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		g->lines++;
	}
	close (fd);
}

void	get_map(char **argv, t_solong *g)
{
	int		fd;
	size_t	i;

	i = 0;
	count_y(argv, g);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\nError while opening the map!\n"), EXIT_FAILURE));
	g->map = malloc(sizeof(char *) * (g->lines + 1));
	if (!g->map)
		exit((ft_printf("Error\nMem error!\n"), free_tab(g->map), EXIT_FAILURE));
	while (i < g->lines)
	{
		g->map[i] = get_next_line(fd);
		if (!g->map[i])
			exit((ft_printf("Error\nMem error!\n"), \
			free_tab(g->map), EXIT_FAILURE));
		i++;
	}
	g->map[i] = NULL;
	close (fd);
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

void	check_walls(t_solong *g)
{
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->x < (ft_strlen(g->map[g->y]) - 1))
		{
			if (g->y == 0 || g->y == (g->lines - 1))
			{
				if (g->map[g->y][g->x] != '1')
					exit((ft_printf("Error\nWall got a hole!\n"), EXIT_FAILURE));
			}
			else
			{
				if (g->map[g->y][0] != '1'
					|| g->map[g->y][ft_strlen(g->map[g->y]) - 2] != '1')
					exit((ft_printf("Error\nWall got a hole!\n"), EXIT_FAILURE));
			}
			g->x++;
		}
		g->y++;
	}
}

void	check_map(t_solong *g)
{
	g->y = 0;
	while (g->y < (g->lines - 1))
	{
		if (ft_strlen(g->map[g->y]) != ft_strlen(g->map[g->y + 1]))
			exit((ft_printf("Error\nMap is not rectangular!\n"), EXIT_FAILURE));
		g->y++;
	}
	g->y = 0;
	while (g->y < g->lines)
	{
		g->x = 0;
		while (g->map[g->y][g->x] != '\0')
		{
			if (g->map[g->y][g->x] != '1' && g->map[g->y][g->x] != '0'
				&& g->map[g->y][g->x] != 'P' && g->map[g->y][g->x] != 'C'
				&& g->map[g->y][g->x] != 'E' && g->map[g->y][g->x] != '\n')
				exit((ft_printf("Error\nWrong input!\n"), EXIT_FAILURE));
			g->x++;
		}
		g->y++;
	}
	if (count_c(g, 'P') != 1 || count_c(g, 'E') != 1 || count_c(g, 'C') < 1)
		exit((ft_printf("Error\nWrong input!\n"), EXIT_FAILURE));
	check_walls(g);
}
