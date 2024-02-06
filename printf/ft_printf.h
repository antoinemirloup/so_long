/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:34:17 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/06 16:29:57 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printpercent(void);
int	ft_printf(const char *s, ...);
int	ft_printptr(void *ptr);
int	ft_printnb(int n);
int	ft_printunb(unsigned int n);
int	ft_printhex(unsigned int n, const char c);

#endif