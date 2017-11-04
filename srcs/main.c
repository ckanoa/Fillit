/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/07/21 19:35:35 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

char		*ft_read(char *file)
{
	int		fd;
	int		read_ret;
	int		i;
	char	tmp[546];
	char	buff[1];

	i = 0;
	read_ret = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error();
	while (read_ret == read(fd, buff, 1))
	{
		tmp[i] = buff[0];
		i++;
		if (i > 545)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

t_block		*ft_store(char *s)
{
	int		block_amt;
	int		j;
	char	c;
	t_block	*block;
	t_block	*tmp;

	j = 0;
	c = 65;
	block_amt = ft_block_amt(s);
	if (!(block = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	tmp = block;
	while (block_amt-- > 0)
	{
		tmp->s = ft_strndup(&s[j], 20);
		ft_checker(tmp->s);
		tmp->c = c++;
		j += 21;
		tmp->next = (t_block*)malloc(sizeof(t_block));
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}

int			main(int argc, char **argv)
{
	t_block	*block;
	char	*readfile;
	char	**res;

	if (argc != 2)
		ft_usage();
	readfile = ft_read(argv[1]);
	block = ft_store(readfile);
	block = ft_initial_xy(block);
	res = ft_result(block, ft_mapsize(block));
	free(block);
	while (*res)
		ft_putendl(*res++);
	return (0);
}
