/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/21 14:57:54 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	find_end(char const *s, int start)
{
	int		i;
	int		end;

	i = start;
	end = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
			end = i;
		i++;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	int		j;
	char	*ret;

	start = find_start(s);
	end = find_end(s, start) + 1;
	if (start > end)
		return ("");
	ret = (char*)malloc((1 + (end - start)) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
