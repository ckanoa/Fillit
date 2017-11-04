/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/16 22:25:32 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\r' ||
			*str == '\f' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		ret = 10 * ret + (*str - '0');
		str++;
	}
	return (ret * sign);
}
