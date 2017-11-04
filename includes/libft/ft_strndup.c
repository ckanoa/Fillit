/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:49:08 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/30 18:50:25 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	char *dest;

	dest = (char *)malloc(n * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strncpy(dest, src, n);
	return (dest);
}
