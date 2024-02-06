/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:41:18 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/08 08:12:31 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long ptr)
{
	int	l;

	l = 0;
	while (ptr > 0)
	{
		ptr = ptr / 16;
		l++;
	}
	return (l);
}

static char	*ft_ptrtoa(unsigned long long ptr)
{
	char	*s;
	int		l;

	l = ft_ptrlen(ptr);
	s = malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[l] = '\0';
	l = l - 1;
	while (l >= 0)
	{
		if ((ptr % 16) <= 9)
			s[l] = '0' + (ptr % 16);
		else if ((ptr % 16) >= 10 && (ptr % 16) <= 15)
			s[l] = 'a' - 10 + (ptr % 16);
		ptr = ptr / 16;
		l--;
	}
	return (s);
}

int	ft_printptr(void *ptr)
{
	int		l;
	char	*s;

	l = 0;
	l = write (1, "0x", 2);
	if (ptr == 0)
		l = l + write(1, "0", 1);
	else
	{
		s = ft_ptrtoa((unsigned long long) ptr);
		l = ft_printstr(s) + 2;
		free(s);
	}
	return (l);
}
