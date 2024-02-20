/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:16:08 by amirloup          #+#    #+#             */
/*   Updated: 2024/02/20 12:51:43 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*d;
	size_t	produit;

	produit = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (produit / nmemb != size)
		return (NULL);
	d = malloc (nmemb * size);
	if (d == NULL)
		return (NULL);
	ft_memset(d, 0, nmemb * size);
	return (d);
}
