/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:38:51 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/10 01:43:28 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_ori.h"

/*
** code de retour:
** si pas de place dans la chaine
**	alors retour de la taille des deux chaine ou bien encore size + size src
** sinon si la taille jusqu au premier /0 est plus eptite que size
**	alors taille + taille de la sous chaine :
**	taille de la chaine normalement creer
**	bien que la chaine peut etre plus petite :)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t count;
	size_t count2;
	size_t end;

	count = 0;
	count2 = 0;
	while (count < size && dst[count])
		count++;
	end = count;
	if (count == size)
		return (size + ft_strlen(src));
	while (src[count2] && count + count2 < size - 1)
	{
		dst[count2 + end] = src[count2];
		count2++;
	}
	if (count < size)
	{
		dst[count2 + end] = '\0';
	}
	return (count + ft_strlen(src));
}
