/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:00:43 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/10 01:45:42 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	u_c;
	size_t			count;

	str = (unsigned char *)s;
	u_c = (unsigned char)c;
	count = 0;
	while (n-- > 0)
	{
		if (u_c == (unsigned char)str[count])
			return (&(str[count]));
		count++;
	}
	return (NULL);
}
