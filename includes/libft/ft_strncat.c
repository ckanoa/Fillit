/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:11:24 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/14 15:49:38 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;
	int		i;

	ret = dest;
	i = 0;
	while (*ret != '\0')
		ret++;
	while (src[i] != '\0' && i < (int)n)
	{
		*ret = src[i];
		ret++;
		i++;
	}
	*ret = '\0';
	return (dest);
}
