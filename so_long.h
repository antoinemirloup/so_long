/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:09:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/07 10:56:22 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_solong
{
	char	**map;
	size_t	x;
	size_t	y;
	size_t	lines;
	size_t	p_x;
	size_t	p_y;
	size_t	e_x;
	size_t	e_y;
}	t_solong;

// Map check
void	get_map(char **argv, t_solong *g);
void	check_map(t_solong *g);
void	free_tab(char **tab);
size_t	count_c(t_solong *g, char c);
void	map_doable(t_solong *g);
void	init_x(t_solong *g);
void	init_y(t_solong *g);
void	spread_x(t_solong *g);
void	spread_y(t_solong *g);

#endif