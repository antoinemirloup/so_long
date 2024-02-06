/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:04:12 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/08 11:50:46 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	l;

	l = 0;
	if (format == 'c')
		l = l + ft_printchar(va_arg(args, int));
	else if (format == 's')
		l = l + ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		l = l + ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		l = l + ft_printnb(va_arg(args, int));
	else if (format == 'u')
		l = l + ft_printunb(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		l = l + ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		l = l + ft_printpercent();
	else
		return (-1);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			l = l + ft_formats(args, s[i + 1]);
			i++;
		}
		else
			l = l + ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (l);
}
