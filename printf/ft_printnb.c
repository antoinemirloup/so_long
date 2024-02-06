/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:45:50 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/07 11:05:02 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(int n)
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

static int	is_n(int n)
{
	int	signe;

	signe = 0;
	if (n < 0)
		signe = 1;
	return (signe);
}

static char	*ft_itoa(int n)
{
	char	*s;
	int		signe;
	long	nb;

	nb = (long) n;
	signe = is_n(n);
	if (signe == 1)
		nb = -nb;
	s = malloc((ft_size(nb) + signe + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[ft_size(nb) + signe] = '\0';
	while (nb)
	{
		s[ft_size(nb) + signe - 1] = '0' + (nb % 10);
		nb = nb / 10;
	}
	if (signe == 1)
		s[0] = '-';
	return (s);
}

int	ft_printnb(int n)
{
	int		l;
	char	*s;

	l = 0;
	if (n == 0)
		l = l + write (1, "0", 1);
	else
	{
		s = ft_itoa(n);
		l = ft_printstr(s);
		free(s);
	}
	return (l);
}
