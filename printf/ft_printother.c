/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printother.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:39:17 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/07 14:06:18 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	if (i == ft_strlen(s))
		return (i);
	else
		return (-1);
}

int	ft_printpercent(void)
{
	return (write (1, "%", 1));
}
