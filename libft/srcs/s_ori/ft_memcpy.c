/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:53:38 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/08 16:41:43 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;

	dest2 = (char *)dst;
	src2 = (char *)src;
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dst);
}
