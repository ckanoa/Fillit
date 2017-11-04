/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/07/19 13:26:51 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_block
{
	char			c;
	char			*s;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}					t_block;

int					main(int argc, char **argv);
char				*ft_read(char *file);
t_block				*ft_store(char *s);
void				ft_error(void);
void				ft_usage(void);
int					ft_block_amt(char *s);
void				ft_checker(char *s);
t_block				*ft_update(t_block *block, int x, int y);
char				**ft_filldots(char **table, int size);
int					ft_mapsize(t_block *block);
t_block				*ft_initial_xy(t_block *block);
char				**ft_result(t_block *block, int size);

#endif
