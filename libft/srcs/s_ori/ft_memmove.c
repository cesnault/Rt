/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:01:38 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 18:01:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dest2;
	char const	*src2;

	dest2 = (char *)dst;
	src2 = (const char *)src;
	if (dest2 < src2)
	{
		while (n > 0)
		{
			*dest2++ = *src2++;
			n--;
		}
	}
	else
	{
		dest2 += n;
		src2 += n;
		while (n)
		{
			*--dest2 = *--src2;
			n--;
		}
	}
	return (dst);
}
