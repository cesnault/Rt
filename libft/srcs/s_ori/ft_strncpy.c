/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegloff <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:42:47 by jegloff           #+#    #+#             */
/*   Updated: 2016/11/04 17:55:17 by jegloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ori.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	while (src[count] && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	while (dest[count] && count < n)
	{
		dest[count] = '\0';
		count++;
	}
	return (dest);
}
