/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/15 16:06:04 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	l;

	l = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	ret = (char*)malloc((1 + l) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret = ft_strcpy(ret, (char*)s1);
	ret = ft_strcat((char*)ret, s2);
	return (ret);
}
