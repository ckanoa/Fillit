/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/07/21 19:35:51 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_usage(void)
{
	ft_putendl("usage: ./fillit [file_name]");
	ft_putendl("\nFile must be properly formatted and contain no more than");
	ft_putendl("26 valid tetriminos as demonstrated in the example below:\n");
	ft_putendl("$> cat -e valid_file.txt");
	ft_putendl("...#$");
	ft_putendl("...#$");
	ft_putendl("...#$");
	ft_putendl("...#$");
	ft_putendl("$");
	ft_putendl("....$");
	ft_putendl("..##$");
	ft_putendl(".##.$");
	ft_putendl("....$");
	ft_putendl("$");
	ft_putendl(".###$");
	ft_putendl("...#$");
	ft_putendl("....$");
	ft_putendl("....$");
	ft_putendl("");
	exit(0);
}

static char	*ft_shapecheck(int i, char *s)
{
	if (s[i] == '#')
	{
		s[i] = 'x';
		s = (ft_shapecheck(i, s));
	}
	if (s[i + 5] == '#')
		s = (ft_shapecheck(i + 5, s));
	if (s[i + 1] == '#')
		s = (ft_shapecheck(i + 1, s));
	if (s[i - 5] == '#')
		s = (ft_shapecheck(i - 5, s));
	if (s[i - 1] == '#')
		s = (ft_shapecheck(i - 1, s));
	return (s);
}

static int	ft_count(char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < 20)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int			ft_block_amt(char *s)
{
	int		i;
	int		pound;
	int		dot;
	int		endl;

	i = 0;
	pound = 0;
	dot = 0;
	endl = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			pound++;
		else if (s[i] == '.')
			dot++;
		else if (s[i] == '\n')
			endl++;
		i++;
	}
	if (pound % 4 != 0 || dot % 12 != 0 || (endl + 1) % 5 != 0)
		ft_error();
	if (pound / 4 < 1)
		ft_error();
	return (pound / 4);
}

void		ft_checker(char *s)
{
	int		i;

	i = 0;
	if (ft_count(s, '.') != 12)
		ft_error();
	while (s[i] != '#')
		i++;
	if (s[i] == '#')
	{
		ft_shapecheck(i, s);
		if (ft_count(s, 'x') != 4)
			ft_error();
	}
	while (s[i] != '\0')
	{
		if (s[i] == 'x')
			s[i] = '#';
		i++;
	}
}
