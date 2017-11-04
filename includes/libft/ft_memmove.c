/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/14 14:33:55 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dst;
	char	*src;
	size_t	i;

	dst = (char*)s1;
	src = (char*)s2;
	i = 0;
	if (src < dst)
	{
		while (n--)
			dst[n] = src[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
