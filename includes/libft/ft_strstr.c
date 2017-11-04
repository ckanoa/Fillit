/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:02:30 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/15 19:19:40 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *needle;
	char *haystack;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		haystack = str;
		needle = to_find;
		while (*str != '\0' && *needle != '\0' && *str == *needle)
		{
			str++;
			needle++;
		}
		if (*needle == '\0')
			return (haystack);
		str = haystack + 1;
	}
	return (0);
}
