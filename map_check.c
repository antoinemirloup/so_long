/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:50:28 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/06 14:09:27 by amirloup         ###   ########.fr       */
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
	int			fd;
	int			i;

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
		i++;
	}
	g->map[i] = NULL;
	close (fd);
}

int	check_size(t_solong *g)
{
	int	i;

	i = 0;
	while (i < (g->lines - 1))
	{
		if (ft_strlen(g->map[i]) != ft_strlen(g->map[i + 1]))
			exit((ft_printf("Error\nMap is not rectangular!\n"), EXIT_FAILURE));
		i++;
	}
	return (1);
}

int	check_map(t_solong *g)
{
	if (check_size(g) != 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_solong	g;

	i = 0;
	get_map(argv, &g);
	if (argc > 1)
	{
		if (check_map(&g) == 1)
		{
			while (g.map[i])
			{
				printf("%s", g.map[i]);
				i++;
			}
			free_tab(g.map);
		}
	}
}
