/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:09:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/15 17:32:08 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 2000
# define HEIGHT 1000

// Map check

typedef struct s_solong
{
	char	**map;
	char	**map_pix;
	size_t	x;
	size_t	y;
	size_t	height;
	size_t	width;
	size_t	p_x;
	size_t	p_y;
	size_t	e_x;
	size_t	e_y;
	size_t	i;
	size_t	j;
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
	mlx_texture_t	*dino;
	mlx_texture_t	*back;
	mlx_texture_t	*bush;
	mlx_texture_t	*nest;
	mlx_texture_t	*bat1;
	mlx_texture_t	*bat2;
	mlx_texture_t	*bat3;
	mlx_texture_t	*fog;
	mlx_texture_t	*success;
	mlx_image_t		*player;
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*exit_nest;
	mlx_image_t		*batt1q;
	mlx_image_t		*batt1r;
	mlx_image_t		*batt1s;
	mlx_image_t		*batt2;
	mlx_image_t		*batt3;
	mlx_image_t		*batt;
	mlx_image_t		*fo;
	mlx_image_t		*succes;
	mlx_image_t		*counter;
}	t_sprite;

typedef struct s_counter
{
	mlx_texture_t	*zero;
	mlx_texture_t	*one;
	mlx_texture_t	*two;
	mlx_texture_t	*three;
	mlx_texture_t	*four;
	mlx_texture_t	*five;
	mlx_texture_t	*six;
	mlx_texture_t	*seven;
	mlx_texture_t	*eigth;
	mlx_texture_t	*nine;
	mlx_image_t		*c0;
	mlx_image_t		*c1;
	mlx_image_t		*c2;
	mlx_image_t		*c3;
	mlx_image_t		*c4;
	mlx_image_t		*c5;
	mlx_image_t		*c6;
	mlx_image_t		*c7;
	mlx_image_t		*c8;
	mlx_image_t		*c9;
}	t_counter;

typedef struct s_game
{
	mlx_t		*mlx;
	int			p_pos_x;
	int			p_pos_y;
	int			p_size_x;
	int			p_size_y;
	int			w_pos_x;
	int			w_pos_y;
	int			w_size_x;
	int			w_size_y;
	int			c_pos_x;
	int			c_pos_y;
	int			c_size_x;
	int			c_size_y;
	int			p_coord_x;
	int			p_coord_y;
	size_t		c_tot;
	size_t		c;
	int			count;
	t_sprite	sprite;
	t_solong	data;
	t_counter	co;
}	t_game;

void	open_window(t_game *g, t_solong *s);
void	destroy_all(t_game *g);
void	player(t_game *g, t_solong *s);
void	background(t_game *g);
void	walls(t_game *g, t_solong *s);
void	set_collectibles(t_game *g);
void	collectibles(t_game *g);
void	fog(t_game *g);
void	exit_game(t_game *g);
void	set_exit(t_game *g);
int		check_up(t_game *g);
int		check_down(t_game *g);
int		check_left(t_game *g);
int		check_rigth(t_game *g);
void	set_fog(t_game *g);
void	numbers(t_game *g);


#endif