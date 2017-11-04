/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 03:49:08 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/15 18:43:45 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		subamt(char const *s, char c)
{
	int i;
	int amt;

	i = 0;
	amt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			amt++;
		i++;
	}
	return (amt);
}

static int		sublen(char const *s, unsigned int start, char c)
{
	int	len;

	len = 0;
	while (s[start] != c && s[start] != 0)
	{
		len++;
		start++;
	}
	return (len);
}

static char		**ft_split(char const *s, char c, char **sa)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
	{
		sa[j] = ft_strsub(s, i, sublen(s, i, c));
		j++;
	}
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			sa[j] = ft_strsub(s, i + 1, sublen(s, i + 1, c));
			j++;
		}
		i++;
	}
	sa[j] = NULL;
	return (sa);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**sa;
	int		amt;

	amt = subamt(s, c);
	sa = (char**)malloc((1 + amt) * sizeof(char*));
	if (sa == NULL)
		return (NULL);
	sa = ft_split(s, c, sa);
	return (sa);
}
