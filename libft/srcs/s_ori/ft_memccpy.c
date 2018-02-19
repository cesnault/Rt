/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:01:16 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/06 17:23:32 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

/*
**ajoute n caractere de la chaine src si on ne rencontre pas
** le caractere c
** y comprit le /0
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				found;
	unsigned char	*dest2;
	unsigned char	*src2;
	unsigned char	cc;

	found = 0;
	cc = (unsigned char)c;
	if (n == 0)
		return (0);
	dest2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n > 0 && !found)
	{
		if (cc == *src2)
			found = 1;
		*dest2 = (unsigned char)*src2;
		dest2++;
		src2++;
		n--;
	}
	if (found == 0)
		return (0);
	return ((unsigned char *)dest2);
}
