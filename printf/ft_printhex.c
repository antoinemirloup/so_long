/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:40:21 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/08 08:11:44 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(unsigned int n)
{
	int	l;

	l = 0;
	while (n > 0)
	{
		n = n / 16;
		l++;
	}
	return (l);
}

static char	*ft_hextoa(unsigned int n, const char c)
{
	char	*s;
	int		l;

	l = ft_size(n);
	s = malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[l] = '\0';
	l = l - 1;
	while (l >= 0)
	{
		if ((n % 16) <= 9)
			s[l] = '0' + (n % 16);
		else if ((n % 16) >= 10 && c == 'x')
			s[l] = 'a' - 10 + (n % 16);
		else if ((n % 16) >= 10 && c == 'X')
			s[l] = 'A' - 10 + (n % 16);
		n = n / 16;
		l--;
	}
	return (s);
}

int	ft_printhex(unsigned int n, const char c)
{
	int		l;
	char	*s;

	l = 0;
	if (n == 0)
		l = l + write (1, "0", 1);
	else
	{
		s = ft_hextoa(n, c);
		l = ft_printstr(s);
		free(s);
	}
	return (l);
}
