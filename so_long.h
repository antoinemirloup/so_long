/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:09:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/09 14:43:43 by amirloup         ###   ########.fr       */
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
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 2048
# define HEIGHT 1024

// Map check

typedef struct s_solong
{
	char	**map;
	size_t	x;
	size_t	y;
	size_t	height;
	size_t	width;
	size_t	p_x;
	size_t	p_y;
	size_t	e_x;
	size_t	e_y;
}	t_solong;

void	get_map(t_solong *g);
void	check_map(t_solong *g);
void	free_tab(char **tab);
size_t	count_c(t_solong *g, char c);
void	map_doable(t_solong *g);
void	init_x(t_solong *g);
void	init_y(t_solong *g);
void	spread_x(t_solong *g);
void	spread_y(t_solong *g);

// MLX

typedef struct s_sprite
{
	mlx_texture_t	*icon;
	mlx_texture_t	*back;
	mlx_texture_t	*bush;
	mlx_image_t		*player;
	mlx_image_t		*background;
	mlx_image_t		*wall;
}	t_sprite;

typedef struct s_game
{
	mlx_t		*mlx;
	t_sprite	sprite;
}	t_game;

void	open_window(t_game *g, t_solong *s);
void	destroy_all(t_game *g);
void	player(t_game *g, t_solong *s);
void	background(t_game *g);
void	walls(t_game *g, t_solong *s);

#endif