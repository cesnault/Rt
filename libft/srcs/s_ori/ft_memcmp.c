/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:56:31 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:56:47 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	str;
	unsigned char	str2;

	if (n <= 0)
		return (0);
	str = *(unsigned char *)s1;
	str2 = *(unsigned char *)s2;
	while ((unsigned char)str == (unsigned char)str2 && --n > 0)
	{
		s1++;
		s2++;
		str = *(unsigned char *)s1;
		str2 = *(unsigned char *)s2;
	}
	return (str - str2);
}
