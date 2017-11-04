/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/07/17 20:47:39 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**ft_resetmap(char **table, t_block *block, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (table[y][x] == block->c)
				table[y][x] = '.';
			x++;
		}
		y++;
	}
	return (table);
}

static char	**ft_tmpsave(char **table, t_block *block, int size)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				table[y][x] = block->c;
				i++;
			}
			x++;
		}
		y++;
	}
	table[y] = NULL;
	return (table);
}

static int	ft_check(char **table, t_block *block, int size)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (block->x[i] == x && block->y[i] == y && table[y][x] != '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char	**ft_solve(char **table, t_block *block, int size)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = NULL;
	if (!block->next)
		return (table);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			block = ft_update(block, x, y);
			if (ft_check(table, block, size))
				tmp = ft_solve(ft_tmpsave(table, block, size),
					block->next, size);
			if (tmp)
				return (tmp);
			table = ft_resetmap(table, block, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

char		**ft_result(t_block *block, int size)
{
	char	**table;

	table = NULL;
	while (table == NULL)
	{
		table = ft_filldots(table, size);
		table = ft_solve(table, block, size);
		size++;
	}
	return (table);
}
