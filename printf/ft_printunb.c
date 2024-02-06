/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:32:08 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/07 13:44:42 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*s;
	long	nb;

	nb = (long) n;
	s = malloc((ft_size(nb) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[ft_size(nb)] = '\0';
	while (nb)
	{
		s[ft_size(nb) - 1] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}

int	ft_printunb(unsigned int n)
{
	int		l;
	char	*s;

	l = 0;
	if (n == 0)
		l = l + write (1, "0", 1);
	else
	{
		s = ft_uitoa(n);
		l = ft_printstr(s);
		free(s);
	}
	return (l);
}
