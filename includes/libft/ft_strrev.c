/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/12 17:20:50 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	buff;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[len + 1] != '\0')
		len++;
	while (len > i)
	{
		buff = str[i];
		str[i] = str[len];
		str[len] = buff;
		i++;
		len--;
	}
	return (str);
}
