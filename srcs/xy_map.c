/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/07/17 20:45:49 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block			*ft_update(t_block *block, int x, int y)
{
	int		i;
	int		minx;
	int		miny;

	minx = 500;
	miny = 500;
	i = 0;
	while (i != 4)
	{
		if (block->x[i] < minx)
			minx = block->x[i];
		if (block->y[i] < miny)
			miny = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - minx + x;
		block->y[i] = block->y[i] - miny + y;
		i++;
	}
	return (block);
}

char			**ft_filldots(char **table, int size)
{
	int		x;
	int		y;

	y = 0;
	table = (char**)malloc(sizeof(char*) * (size + 1));
	if (table == NULL)
		return (NULL);
	while (y < size)
	{
		table[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			table[y][x] = '.';
			x++;
		}
		y++;
	}
	table[y] = NULL;
	return (table);
}

int				ft_mapsize(t_block *block)
{
	int		i;
	int		size;

	i = 0;
	size = 2;
	while (block->next)
	{
		i++;
		block = block->next;
	}
	while ((size * size) < (i * 4))
		size++;
	return (size);
}

static t_block	*ft_record_xy(t_block *block, char **sa)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (sa[y])
	{
		x = 0;
		while (sa[y][x])
		{
			if (sa[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_block			*ft_initial_xy(t_block *block)
{
	t_block	*tmp;

	tmp = block;
	while (block->next)
	{
		block = ft_record_xy(block, ft_strsplit(block->s, '\n'));
		free(block->s);
		block = block->next;
	}
	return (tmp);
}
