/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:49:08 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/14 15:16:07 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char *dest;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == '\0')
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
