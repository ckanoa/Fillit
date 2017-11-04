/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/16 23:34:03 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*intminplacer(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*placechar(char *str, int s, int i, int n)
{
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (s < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		s;
	int		i;

	i = 0;
	s = 1;
	str = (char*)malloc((1 + ft_get_digits(n)) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		s = -1;
		n = -n;
	}
	if (n == -2147483648)
	{
		str = intminplacer(str);
		return (str);
	}
	str = placechar(str, s, i, n);
	return (ft_strrev(str));
}
