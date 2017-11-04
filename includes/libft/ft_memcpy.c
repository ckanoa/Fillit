/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckanoa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:42:45 by ckanoa            #+#    #+#             */
/*   Updated: 2017/06/12 14:33:07 by ckanoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char		*dptr;
	const char	*sptr;

	dptr = (char*)dest;
	sptr = (const char*)src;
	while (n != 0)
	{
		*dptr = *sptr;
		dptr++;
		sptr++;
		n--;
	}
	return (dest);
}
