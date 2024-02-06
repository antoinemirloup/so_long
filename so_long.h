/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:09:39 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/06 14:47:08 by amirloup         ###   ########.fr       */
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
}	t_solong;

void	free_tab(char **tab);

#endif