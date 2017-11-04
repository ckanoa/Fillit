/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/12 15:10:49 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != '\0')
		ptr++;
	while (*ptr != *str)
	{
		if (*ptr != (char)c)
			ptr--;
		else
			return (ptr);
	}
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}
